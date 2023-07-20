import paho.mqtt.client as mqtt
from pymongo import MongoClient
from datetime import datetime
# MQTT settings
mqtt_host = "localhost"
mqtt_port = 1883
mqtt_topic = "your_mqtt_topic"

# MongoDB settings
mongo_uri = "mongodb://localhost:27017/"
mongo_db = "weatherDHT"
mongo_collection = "weather"

# Connect to MongoDB
client = MongoClient(mongo_uri)
db = client[mongo_db]
collection = db[mongo_collection]

# Define MQTT callbacks
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe(mqtt_topic)

def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.payload))
    # Parse the MQTT message and insert data into MongoDB
    data = msg.payload.decode().split(",")
    temperature = float(data[0])
    humidity = float(data[1])
    document = {"temperature": temperature, "humidity": humidity, "timestamp": datetime.utcnow()}
    collection.insert_one(document)

# Set up MQTT client and callbacks
client = mqtt.Client()
client.username_pw_set("myuser", "1")
client.on_connect = on_connect
client.on_message = on_message
# Assigning the function `on_message` to the `client.on_message` variable.
client.connect(mqtt_host, mqtt_port, 60)

# Start the MQTT client loop
client.loop_forever()
