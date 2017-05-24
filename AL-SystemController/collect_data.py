import sqlite3
import RPi.GPIO as GPIO
import os
import time
import requests
from envirophat import light, weather, analog

os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')

temp_sensor = '/sys/bus/w1/devices/28-00000829846d/w1_slave'

def temp_raw():

    f = open(temp_sensor, 'r')
    lines = f.readlines()
    f.close()
    return lines

def read_temp():

    lines = temp_raw()
    while lines[0].strip()[-3:] != 'YES':
        time.sleep(0.2)
        lines = temp_raw()
    temp_output = lines[1].find('t=')

    if temp_output != -1:
        temp_string = lines[1].strip()[temp_output+2:]
        temp_c = float(temp_string) / 1000.0
        return temp_c

conn = sqlite3.connect('server.db')
c = conn.cursor()

GPIO.setmode(GPIO.BCM)
GPIO.setup(22, GPIO.OUT)
GPIO.output(22, GPIO.HIGH) 

try:
  lux = light.light()
  rgb = str(light.rgb())[1:-1].replace(' ', '')  
  temp = int(weather.temperature())
  press = int(weather.pressure())
  water1 = analog.read(0)
  waterTemp = read_temp();

  if water1 < 0.5:
    r = requests.get('http://127.0.0.1:5000/relay/1/0')
  else:
    r = requests.get('http://127.0.0.1:5000/relay/1/1')

  datavals = [('light', lux),
             ('rgb', rgb),
             ('temp', temp),
             ('press', press),
             ('water1', water1),
             ('watertemp', waterTemp)
             ]
  c.executemany('INSERT INTO sensor_log (sensor, value) VALUES (?, ?)', datavals) 

  conn.commit()
  conn.close()
  GPIO.cleanup()



except KeyboardInterrupt:
  print "Done!"
