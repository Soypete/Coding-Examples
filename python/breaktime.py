import webbrowser
import time

count = 0

print("This program started on "+time.ctime())
while (count < 3):
    time.sleep(10)
    webbrowser.open_new("https://youtu.be/YBpdL9hSac4?t=10s")
    count= 1+count

    
