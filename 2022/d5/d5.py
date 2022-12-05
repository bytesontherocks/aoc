import queue
import re

def parseStacks(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    ln_stack =[]
    l_ix = 0
    for line in lines:
        # parse stacks       
        if line == "\n":
            break
        l_ix += 1
        ln_stack.append(line)

    print(ln_stack)

    num_qs= int(ln_stack[-1][-3])#last element
    max_stack = len(ln_stack) - 1

    queues = []
    for q in range(0, num_qs):
        q_t = queue.LifoQueue()
        for el_ix in range(0, max_stack):
            el = ln_stack[-el_ix-2][1 + q * 4]
            if el != " ":
                q_t.put(el)
            else:
                break
        queues.append(q_t)

    return queues

def calculateScoreEx1(input_file_name):    
   
    qs = parseStacks(input_file_name)    

    f = open(input_file_name, "r")
    lines = f.readlines()

    ln_ix = 0 
    while lines[ln_ix] != "\n":
        ln_ix+=1
    
    ln_ix+=1
    moves = 0
    q_from = 0
    q_to = 0

    for line_ix in range(ln_ix,len(lines)):
        move_data = re.findall(r'\d+', lines[line_ix])
        moves = int(move_data[0])
        q_from = int(move_data[1])-1
        q_to =int( move_data[2])-1
        print(f"moves:{moves}, from: {q_from}, to: {q_to}")

        for time in range(0,moves):
            qs[q_to].put(qs[q_from].get())

    message=""
    for q in qs:
        message += q.get()
    

    return message

def calculateScoreEx2(input_file_name):    
   
    qs = parseStacks(input_file_name)    

    f = open(input_file_name, "r")
    lines = f.readlines()

    ln_ix = 0 
    while lines[ln_ix] != "\n":
        ln_ix+=1
    
    ln_ix+=1
    moves = 0
    q_from = 0
    q_to = 0

    for line_ix in range(ln_ix,len(lines)):
        move_data = re.findall(r'\d+', lines[line_ix])
        moves = int(move_data[0])
        q_from = int(move_data[1])-1
        q_to =int( move_data[2])-1
        print(f"moves:{moves}, from: {q_from}, to: {q_to}")

        # not optimal
        q_t = queue.LifoQueue()
        for time in range(0,moves):
            q_t.put(qs[q_from].get())

        for time in range(0,moves):     
            qs[q_to].put(q_t.get())

    message=""
    for q in qs:
        message += q.get()
    

    return message

        
if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")