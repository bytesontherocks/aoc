import queue

def calculateScoreEx1(input_file_name):
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

    num_qs= int(ln_stack[-1][-3])#last element
    max_stack = len(ln_stack) - 1
    #print(num_qs)
    #print(max_stack)
    # print(f"s1: {ln_stack[-2][1]} s2: {ln_stack[-2][5]}, s3: {ln_stack[-2][9]}")
    for q in range(0, num_qs):
        for el_ix in range(0, max_stack):
            el = ln_stack[-el_ix-2][1 + (q * 4)]
            if el != "":
                print(el)

    # print(ln_stack)


    # parse moves
    
    #q = queue.LifoQueue()

    score = 0
    

    return score

def calculateScoreEx2(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    score = 0
  

    return score

        
if __name__ == "__main__":
    res1 = calculateScoreEx1("input_sample.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")