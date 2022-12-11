
import re

class Monkey:
    worry_items=[]
    worry_new=[]
    test=1
    test_true=1
    test_false=1
    inspection=0

    def __init__(self,worry_items, worry_new, test, t_true,t_false):
        self.worry_items=worry_items
        self.worry_new=worry_new
        self.test=test
        self.test_true=t_true
        self.test_false=t_false
    
    def printList(self):
        for it in self.worry_items:
            print(it)
    
    def calculateNew(self, old) -> int:
        if self.worry_new[0].isalpha():
            return old * old
        if self.worry_new[1] == '+':
            return int(self.worry_new[0]) + old
        if self.worry_new[1] == '*':
            return int(self.worry_new[0]) * old
    
    def inspect(self, monkeys):
        for it in self.worry_items:
            new=self.calculateNew(it)
            calc=int(new/self.test)
            self.inspection+=1






def calculateScoreEx1(input_file_name):    

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
                alist = re.findall(r'\d+',ln)
                # for it in alist:
                #     print(it)
                monkeys_it.append(alist)
                
                ln=lines[ln_ix+2].split()
                op=[]
                op.append(ln[-1])
                op.append(ln[-2])
                
                test=re.findall(r'\d+',lines[ln_ix+3])                
                test_t=re.findall(r'\d+',lines[ln_ix+4])
                test_f=re.findall(r'\d+',lines[ln_ix+5])
                #print(f"test:{test[0]}, ttrue{test_t}, tfalse{test_f}")
                
                m=Monkey(alist,op,test,test_t,test_f)  
                monkeys.append(m)
            
            ln_ix+=1
        
        for m in monkeys:
            print(f"monkey ix {m}")
            m.printList()
            
            
        #print(monkeys)


        # its = getMonkeyItems()
        # worry_level = getWorryLevel()

        # worry_level/=3

        # applyTest()
        # decideMonkey()


        
    return 0


def calculateScoreEx2(input_file_name):    
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
       

    return 0

if __name__ == "__main__":
    res1 = calculateScoreEx1("input_sample.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")