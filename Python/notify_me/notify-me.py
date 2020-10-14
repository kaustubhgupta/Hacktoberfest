from plyer import notification
import os, time

desk_dir = os.path.join(os.environ["HOMEPATH"], "Desktop")
notifylist_dir = os.path.join(desk_dir, "notify-me.txt")

def get_todo():
    todo = []
    if not os.path.isfile(notifylist_dir):
        print('No "notify-me.txt" file in your desktop, now create one for you...')
        with open(notifylist_dir, 'w') as file:
            file.write('# Put your todo item below ...'
                + '\n# Use "#" mark to make comment'
            )
    else:
        with open(notifylist_dir, 'r') as file:
            for line in file:
                if line[0] != "#" :
                    todo.append(line.replace('\n', ''))
    
    return [i for i in todo if i != '']

def notify(todos):
    for todo in todos:
        notification.notify(
            title='ToDo notification (notify-me)',
            message=todo,
            app_icon=os.path.join(os.path.dirname(__file__),'Paperclip.ico'),
            timeout=5,
        )
        time.sleep(5.5)

def main():
    while True:
        todos = get_todo()
        notify(todos)
        time.sleep(60*60*4)

if __name__ == "__main__":
    main()