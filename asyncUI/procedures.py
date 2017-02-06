import tkinter
import uuid
import threading
import queue
import time


class Procedure(threading.Thread):
    def __init__(self, result_queue):
        super().__init__()
        self.result_queue = result_queue
        self.mid_result = Result()
        self.complete_result = Result()

    def enqueue_result(self, result, data=None):
        r = Result(result.handler)
        r.data = data
        self.result_queue.put(r)

    def run(self):
        time.sleep(2)
        self.enqueue_result(self.mid_result, 1)
        time.sleep(2)
        self.enqueue_result(self.mid_result, 2)
        time.sleep(2)
        self.enqueue_result(self.mid_result, 3)
        self.enqueue_result(self.complete_result)
        


class Result:
    def __init__(self, handler=None, data=None):
        self._id = uuid.uuid1()
        self.data = data
        self.handler = handler


class TkApp(tkinter.Tk):
    def __init__(self, queue_time=0):
        super().__init__()
        self.queue_time = queue_time
        self.result_queue = queue.Queue()
        self.after(self.queue_time, self.check_queue)

        self.p = Procedure(self.result_queue)
        self.p.complete_result.handler = self.doAsyncThing
        self.p.mid_result.handler = self.doAsyncThing
        
        
    def check_queue(self):
        if not self.result_queue.empty():
            result = self.result_queue.get(block=False)
            result.handler(result.data)
        self.after(self.queue_time, self.check_queue)

    def doThingNow(self):
        print("Doing a thing RIGHT NOW!")

    def doSlowThing(self):
        print("Starting a slow thing.")
        time.sleep(3)
        print("Slow thing over.")

    def doAsyncSlowThing(self):
        print("Starting an asynchronous slow thing.")
        self.p.start()
        print("Asynchronous slow thing running in the background.")

    def doAsyncThing(self, data):
        if data is None:
            print("All done!")
        else:
            print("Result is " + str(data))



root = TkApp(queue_time=20)

root.geometry("600x400+200+200")
root.title("Procedure tester")

frame = tkinter.Frame(root, borderwidth=2, relief=tkinter.SUNKEN)
frame.pack(fill=tkinter.BOTH, side=tkinter.LEFT, expand=True)
doNowButton = tkinter.Button(frame,
                             text="Do Something Now",
                             command=root.doThingNow)
doNowButton.pack(fill=tkinter.X)
doSlowThingButton = tkinter.Button(frame,
                                   text="Do Something Slow",
                                   command=root.doSlowThing)
doSlowThingButton.pack(fill=tkinter.X)
doAsyncSlowThingButton = tkinter.Button(frame,
                                        text="Do Something Async",
                                        command=root.doAsyncSlowThing)
doAsyncSlowThingButton.pack(fill=tkinter.X)

root.mainloop()

"""
API for a procedure:
Create it
Register results with functions to execute on return
Start it
Check the result queue in the main loop
When there's a result in the queue, run the registered function

"""
