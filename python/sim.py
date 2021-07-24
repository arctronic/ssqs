import numpy as np

class Simulation:
    def __init__(self):
        self.num_customers = 0
        self.clock = 0
        self.t_arrival = self.generate_inter_arrival()
        self.t_depart = float('inf')
        self.num_arrival =0
        self.num_depart = 0
        self.total_wait = 0.0

    def advanceTime(self):
        t_event = min(self.t_arrival,self.t_depart)
        self.total_wait += self.num_customers*(t_event-self.clock)
        self.clock = t_event
        if self.t_arrival<=self.t_depart:
            self.handleArrival()
        else:
            self.handleDepurture()

    def handleArrival(self):
        self.num_customers+=1
        self.num_arrival+=1
        if self.num_customers<=1:
            self.t_depart = self.clock() + self.generate_service()

        self.t_arrival = self.generate_inter_arrival() + self.clock

    def handleDepurture(self):
        self.num_customers-=1
        self.num_depart+=1
        if self.num_customers>0:
            self.t_depart = self.clock + self.generate_service()
        else:
            self.t_depart = float('inf')

    def generate_inter_arrival(self):
        return np.random.exponential(1./3)

    def generate_service(self):
        return np.random.exponential(1./4)

x = Simulation()
np.random.seed(0)
print(x.t_arrival)