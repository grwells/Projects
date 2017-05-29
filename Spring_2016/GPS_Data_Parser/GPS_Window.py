'''
Created on Apr 14, 2016

@author: deepg
'''
import tkinter as tk
import Ultimate_GPS_Tracker

class Application(tk.Frame):
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        self.random_Button = tk.Button(self)
        self.random_Button["text"] = "Welcome to the Ultimate GPS Tracker\n(click me)"
        self.random_Button["command"] = self.start_GPS
        self.random_Button.pack(side="top")
        

        self.QUIT = tk.Button(self, text="QUIT", fg="red",
                                            command=root.destroy)
        self.QUIT.pack(side="bottom")
        
    def start_GPS(self):
        Ultimate_GPS_Tracker.start_Process()

    def say_hi(self):
        print("hi there, everyone!")

root = tk.Tk()
app = Application(master=root)
app.mainloop()