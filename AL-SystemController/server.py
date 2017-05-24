import RPi.GPIO as GPIO
import bluetooth
import json
import sqlite3
import os
from flask import Flask, redirect, g, jsonify



DATABASE = 'server.db'

BTMAC = '98:D3:32:30:86:CD'
BTPORT = 1
btsocket = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
btsocket.connect((BTMAC,BTPORT))

app = Flask(__name__)


relays = {
  '1': {'0': 'a', '1': 'b', 'status': 0 },
  '2': {'0': 'c', '1': 'd', 'status': 0 },
  '3': {'0': 'e', '1': 'f', 'status': 0 },
  '4': {'0': 'g', '1': 'h', 'status': 0 },
  '5': {'0': 'i', '1': 'j', 'status': 0 },
  '6': {'0': 'k', '1': 'l', 'status': 0 },
  '7': {'0': 'm', '1': 'n', 'status': 0 },
  '8': {'0': 'o', '1': 'p', 'status': 0 }
}

def make_dicts(cursor, row):
  return dict((cursor.description[idx][0], value)
    for idx, value in enumerate(row))

def get_db():
  db = getattr(g, '_database', None)
  if db is None:
    db = g._database = sqlite3.connect(DATABASE)
  db.row_factory = make_dicts
  return db

@app.teardown_appcontext
def close_connection(exception):
  db = getattr(g, '_database', None)
  if db is not None:
    db.close()



def query_db(query, args=(), one=False):
    cur = get_db().execute(query, args)
    rv = cur.fetchall()
    cur.close()
    return (rv[0] if rv else None) if one else rv



@app.route("/")
def index():
  return redirect('static/index.html')


@app.route("/relay/<id>/<status>")
def relay(id=None,status=None):
  #btsocket.connect((BTMAC,BTPORT))
  btsocket.send(relays[id][status])
  relays[id]['status'] = int(status) 
  '''
  GPIO.setmode(GPIO.BCM)
  GPIO.setup(int(relays[id]['pin']), GPIO.OUT)
  if status == 'on':
    GPIO.output(int(relays[id]['pin']), GPIO.HIGH)
    relays[id]['status'] = True
  else:
    GPIO.output(int(relays[id]['pin']), GPIO.LOW)
    relays[id]['status'] = False
  '''
  #btsocket.close()
  return 'ok'


@app.route("/camera/on")
def camera_on():
  os.system("python cam.py &")
  return "On!"


@app.route("/relay_status")
def status():
  return jsonify(relays)


@app.route("/latest")
def latest():
  query = '''SELECT a.sensor, a.timestamp, a.value FROM sensor_log AS a INNER JOIN (SELECT sensor, MAX(timestamp) AS timestamp FROM sensor_log GROUP BY sensor) AS b ON a.sensor     = b.sensor AND a.timestamp = b.timestamp'''
  return jsonify(query_db(query))

if __name__ == "__main__":
    app.run(host= '0.0.0.0', debug=True)


GPIO.cleanup()
