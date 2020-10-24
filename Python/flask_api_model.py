# First things first
# Let's make all imports that we need: the flask and the cors library to make our app
from flask import Flask
from flask_cors import CORS, cross_origin

# This library is to make date operations
from datetime import datetime, timedelta 


# Initializing our flask app and using cors
app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'


# Set a main route to calls for our api from browser
@app.route('/')
@cross_origin()
def home():
    return 'Hello Flask API'


# A route example getting de brazilian date-hour for now
@app.route('/api/brazildate', methods=['GET'])
@cross_origin()
def get_date():
    # The simple way to do this is using datetime and decreasing 3 hours from the UTC time
    return (datetime.now() - timedelta(hours=3)).strftime("%d/%m/%Y %H:%M:%S")


# To run an python app
if __name__ == "__main__":
    # Use app.run to run your flask app :)
    app.run(threaded=True, port=5000)


# Any questions? Call me: @gabrielf_dev in Twitter