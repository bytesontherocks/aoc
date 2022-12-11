
import re

class Monkey:
    worry_items=[]
    worry_new_operand=0
    worry_new_operation=0
    test=1
    test_true=1
    test_false=1
    inspection=0

    def __init__(self,worry_items, worry_new, test, t_true,t_false):
        self.worry_items=worry_items
        self.test=test
        self.test_true=t_true
        self.test_false=t_false        
        if worry_new[0].isdigit():
            self.worry_new_operand = int(worry_new[0])
            if worry_new[1] == '+':
                self.worry_new_operation=1
            else:
                self.worry_new_operation=2
        

    
    def printList(self):
        for it in self.worry_items:
            print(it)
    
    def calculateNew(self, old) -> int:
        if self.worry_new_operation==0:
            return old * old
        elif self.worry_new_operation == 1:
            return self.worry_new_operand + old
        else:
            return self.worry_new_operand * old

    def addWorryItem(self, item):
        self.worry_items.append(item)
    
    def inspect(self, monkeys):
        for it in self.worry_items:
            new=self.calculateNew(int(it))
            boredom=int(new/3)
            if boredom%self.test==0:
                monkeys[self.test_true].addWorryItem(boredom)
            else:
                monkeys[self.test_false].addWorryItem(boredom)

            self.inspection+=1

        self.worry_items.clear()#items processed
    
    def inspect_ex2(self, monkeys):
        m1=monkeys[self.test_true]
        m2=monkeys[self.test_false]
        for it in self.worry_items:
            new=self.calculateNew(it)
            if new%self.test==0:
                m1.addWorryItem(new)
            else:
                m2.addWorryItem(new)

        
        self.inspection+=len(self.worry_items)
        self.worry_items.clear()#items processed

    def getInspectedItems(self) -> int:
        return self.inspection


def calculateScoreEx1(input_file_name):    

    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        monkeys_it = []
        monkeys=[]

        ln_ix=0
        while ln_ix<len(lines):
            ln=lines[ln_ix]
           
            if "Monkey" in ln:   
                ln=lines[ln_ix+1]
                alist=[]
                alist = re.findall(r'\d+',ln)
                monkeys_it.append(alist)
                
                ln=lines[ln_ix+2].split()
                op=[]
                op.append(ln[-1])
                op.append(ln[-2])
                
                test=re.findall(r'\d+',lines[ln_ix+3])                
                test_t=re.findall(r'\d+',lines[ln_ix+4])
                test_f=re.findall(r'\d+',lines[ln_ix+5])
                
                m=Monkey(alist,op,int(test[0]),int(test_t[0]),int(test_f[0]))  
                monkeys.append(m)
            
            ln_ix+=1
        
        num_rounds=20
        for rounds in range(0,num_rounds):
            for m in monkeys:
                m.inspect(monkeys)
            rounds+=1
        
        m=0
        inspected=[]
        for m in range(0,len(monkeys)):
            print(f"monkey {m} : {monkeys[m].getInspectedItems()}")
            inspected.append(monkeys[m].getInspectedItems())
        inspected.sort()
        print(inspected)
                      
    return inspected[-1]*inspected[-2]


def calculateScoreEx2(input_file_name):    
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        monkeys_it = []
        monkeys=[]

        ln_ix=0
        while ln_ix<len(lines):
            ln=lines[ln_ix]
           
            if "Monkey" in ln:             
                mIx=ln[-2]
                ln=lines[ln_ix+1]
                alist=[]
                alist2 = re.findall(r'\d+',ln)
                for it in alist2:
                    alist.append(int(it))
                    
                monkeys_it.append(list(map(int, alist)))
                
                ln=lines[ln_ix+2].split()
                op=[]
                op.append(ln[-1])
                op.append(ln[-2])
                
                test=re.findall(r'\d+',lines[ln_ix+3])                
                test_t=re.findall(r'\d+',lines[ln_ix+4])
                test_f=re.findall(r'\d+',lines[ln_ix+5])
                
                m=Monkey(alist,op,int(test[0]),int(test_t[0]),int(test_f[0]))  
                monkeys.append(m)
            
            ln_ix+=1
        
        num_rounds=1000
        for rounds in range(0,num_rounds):
            for m in monkeys:
                m.inspect_ex2(monkeys)
            rounds+=1
        
        m=0
        inspected=[]
        print("---------------")
        print("Ex2:")
        for m in range(0,len(monkeys)):
            print(f"monkey {m} : {monkeys[m].getInspectedItems()}")
            inspected.append(monkeys[m].getInspectedItems())
        inspected.sort()
                      
    return inspected[-1]*inspected[-2]

if __name__ == "__main__":
    res1 = calculateScoreEx1("input_sample.txt")
    res2 = calculateScoreEx2("input_sample.txt")
    print(f"ex1: {res1}, ex2: {res2}")