from tkinter import *
from tkinter import ttk
import serial
from threading import *
import time

ser = serial.Serial('COM2')
readData = ''
totalPrice = 0

def infinite_loop():
    global readData
    global tree
    global totalPrice
    global lbl1
    while 1:
        data = ser.read().decode()
        if data == '\n':
            print(readData)
            x = readData.split(':')
            readData=''
            tree.insert('', 'end',text = "1", values = (x[0], x[1], x[2]))
            totalPrice = totalPrice+float(x[2])
            lbl1.config(text = "Total Price:  " + str(totalPrice))
            continue
        readData = readData + data

def start():
    t1 = Thread(target=infinite_loop)
    t1.start()

def reset():
    global totalPrice
    global lbl1
    global tree
    totalPrice = 0
    lbl1.config(text = "Total Price:  " + str(totalPrice))
    for item in tree.get_children():
        tree.delete(item)


root = Tk()
root.title("Pricing app")
root.geometry('1000x650')
#root.grid_rowconfigure(0, weight = 1)
root.grid_columnconfigure(0, weight = 1)

s = ttk.Style()
s.theme_use('clam')



tree = ttk.Treeview(root, columns = ("c1", "c2", "c3"), show='headings')
tree.column("# 1", anchor=CENTER)
tree.heading("# 1", text="Type")
tree.column("# 2", anchor=CENTER)
tree.heading("# 2", text="quantity")
tree.column("# 3", anchor=CENTER)
tree.heading("# 3", text="Price")



lbl = Label(root, text = "Welcome to pricing App")
lbl.grid()
lbl.grid_rowconfigure(1, weight = 1)
lbl.grid_columnconfigure(1, weight = 1)
tree.grid()
lbl1 = Label(root, text = "Total Price:  " + str(totalPrice))
lbl1.grid()

button = Button(root, text = "Reset", command = reset)
button.grid()

root.after(1000, start)


root.mainloop()

