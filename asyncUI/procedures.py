import threading
import queue
import time


class Result:
    def __init__(self, handler=None, data=None):
        self.data = data
        self.handler = handler


class Procedure(threading.Thread):
    def __init__(self, result_queue):
        super().__init__()
        self.result_queue = result_queue

    def enqueue_result(self, result, data=None):
        r = Result(result.handler, data)
        self.result_queue.put(r)

    # This is the method you need to override.
    def run(self):
        """
        This method needs to be overridden. It will execute when the
        Procedure.start() method is called. While executing, you can
        use the enqueue_result method to put Result objects in the queue.
        The handler property of the Result will execute when the main
        loop dequeues that Result.
        """
        raise NotImplementedError        

   
class DemoProcedure(Procedure):
    def __init__(self, result_queue):
        super().__init__(result_queue)
        self.mid_result = Result()
        self.end_result = Result()

    def run(self):
        print("Asynchronous thing is happening...")
        time.sleep(1)
        self.enqueue_result(self.mid_result, 1)
        time.sleep(1)
        self.enqueue_result(self.mid_result, 2)
        time.sleep(1)
        self.enqueue_result(self.mid_result, 3)
        self.enqueue_result(self.end_result)
