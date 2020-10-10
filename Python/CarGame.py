# A fun and interactive Python Car Game


# Declaring the variables
command = ""
started = ""

while True:
    command = input("> ")
    if command.lower() == "start":
        if started:
            print("Car already started" )
        else:
            started = True
            print("Car started...")

    elif command.lower() == "stop":
        if not started:
            print("Car already stopped!")
        else:
            started = False
            print("Car stopped")
    elif command == "help":
        print("""
        start - to start the car
        stop - to stop the car
        quit - to quit
        """)
    elif command == "quit":
        break
    else:
        print("Sorry! I didn't understand that!")