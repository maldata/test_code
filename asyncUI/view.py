import procedures
import tkinter
import time
import queue


class BaseView(tkinter.Tk):
    def __init__(self, queue_time=1):
        super().__init__()
        self.queue_time = queue_time
        self.result_queue = queue.Queue()
        self.after(self.queue_time, self.check_queue)
        
    def check_queue(self):
        if not self.result_queue.empty():
            result = self.result_queue.get(block=False)
            result.handler(result.data)
        self.after(self.queue_time, self.check_queue)


class View:
    def __init__(self):
        self.root = BaseView(queue_time=10)
        self.root.geometry("600x400+200+200")
        self.root.title("Procedure tester")

        frame = tkinter.Frame(self.root, borderwidth=2, relief=tkinter.SUNKEN)
        frame.pack(fill=tkinter.BOTH, side=tkinter.LEFT, expand=True)
        self.doNowButton = tkinter.Button(frame,
                                          text="Do Something Now",
                                          command=self.doThingNow)
        self.doNowButton.pack(fill=tkinter.X)
        self.doSlowThingButton = tkinter.Button(frame,
                                                text="Do Something Slow",
                                                command=self.doSlowThing)
        self.doSlowThingButton.pack(fill=tkinter.X)
        self.doAsyncSlowThingButton = tkinter.Button(frame,
                                                     text="Do Something Async",
                                                     command=self.doAsyncSlowThing)
        self.doAsyncSlowThingButton.pack(fill=tkinter.X)

        self.p = procedures.DemoProcedure(self.root.result_queue)
        self.p.mid_result.handler = self.handle_result
        self.p.end_result.handler = self.handle_result
        
    def runUI(self):
        self.root.mainloop()

    def doThingNow(self):
        print("Doing a thing RIGHT NOW!")

    def doSlowThing(self):
        print("Starting a slow thing.")
        time.sleep(3)
        print("Slow thing over.")

    def doAsyncSlowThing(self):
        print("Starting an asynchronous slow thing.")
        self.p.start()
        print("Asynchronous slow thing started.")

    def handle_result(self, data):
        if data is None:
            print("Done!")
        else:
            print("Result returned:" + str(data))
            

def main():
    app = View()
    app.runUI()

if __name__=='__main__':
    main()
    
