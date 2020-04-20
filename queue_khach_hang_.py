class Customer:
    def __init__(self, idNumber, arrivalTime):
        self.id = idNumber
        self.arrivalTime = arrivalTime

class Counter:
    def __init__(self, idNumber):
        self.id = idNumber
        self.customer = None
        self.stopTime = -1

    def startServe(self, customer, stopTime):
        self.customer = customer
        self.stopTime = stopTime

    def stopServe(self):
        curCustomer = self.customer
        self.customer = None
        return curCustomer

    def isFree(self):
        return self.customer is None

    def isComplete(self, curTime):
        return self.stopTime == curTime and self.customer is not None
# from DSA_queue_linkedkist import Queue 2
import random as rd
class Stimulation:
    def __init__(self, nCounters,betweenTime, serviceTime, sTime): #nCounter - so luong tong Counter bang bao nhieu
        # sTime - stimulation Time

        self.betweenTime = betweenTime
        self.serviceTime = serviceTime
        self.sTime = sTime
        self.customerQueue = Queue2()
        self.counters[i] = [None] * nCounters

        for i in range(Counters):
            self.counters[i] = Counter(i+1)

    def handleSrrival(self, curTime):
        prob = rd.randint(1, self.betweenTime)
        if prob == 1: #a new customer is coming
            curId = self.nCustomers + 1
            newCus = Customer(curId, curTime)
            self.customerQueue.enqueue(newCus)
            self.nCustomers += 1
            print("Time {}: Customer {} arrived.".format(curTime, curId))
    def handlebeginService(self, curTime):
        for customer in self.counters:
            if counter.isFree and not self.customerQueue.isEmpty():
                curCustomer = self.customerQueue.dequeue()
                counter.startservice(curCustomer, curTime + self.serviceTime)
                print("Time {} Counter {} started serving cusutomer{}".format(curTime, counter.id, customer.id))
    def handleService(self, curTime):
        for counter in self.counter:
            if counter.iscomplete(curTime):
                print("Time {} Counter {} stopped serving customer {}". format(curTime, counter.id, counter))
                counter.stopServe()

    def run(self):
        print("Begin Stimulation")
        for iTime in range(self.sTime):
            self.handleArrival(iTime)
            self.handleBeginServe(iTime)
            self.handleEndServe(iTime)
        print("End of stimulation")

    def report(self):
        print("--------------------")
        nServedCustomer = self.nCustomers - self.customerQueue.size
        print("The number of customer served ", nServedCustomer)
        print("The number of customer remaining in line: ", self.customerQueue.size)

