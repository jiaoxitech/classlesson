CREATE TABLE sensor_log ( sensor TEXT,  timestamp DATE DEFAULT (datetime('now','localtime')), value TEXT );
CREATE INDEX sensor_idx ON sensor_log ( sensor, timestamp );
