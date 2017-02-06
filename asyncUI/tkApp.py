import tkinter
import queue


class TkApp(tkinter.Tk):
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
        
