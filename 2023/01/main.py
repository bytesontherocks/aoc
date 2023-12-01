


def calculate_ex1(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    res = []
    for line in lines:
        #print(line)
        dig = []
        for ch in line:
            if ch.isdigit():
                dig.append(ch)
                #print(ch)
        d = int(dig[0])*10
        d += int(dig[-1])
        #print(d)
        res.append(d)
    sum = 0
    for r in res:
        sum += int(r)
    return sum

def replaceAlphaStrings(l):
    numbers_alpha = {"one" : '1', "two": '2', "three": '3', 
          "four": '4', "five": '5', "six" : '6', "seven" : '7', 
          "eight" : '8', "nine" : '9'}
    print(l)
    indexes= []
    dic = {}
    for n in numbers_alpha:   
        ix = l.find(n)     
        indexes.append(ix)
        dic[ix]= n
    
    if len(indexes) > 0:
        idx_list = [index for index in indexes if index > -1]
        if len(idx_list) > 0:
            first = min(idx_list)
            last = max(idx_list)
            #if first >= 0:
            l = l.replace(dic[first], numbers_alpha[dic[first]])
            #if last >= 0:
            l = l.replace(dic[last], numbers_alpha[dic[last]])
        else:
            print(f"Line no alpha num: {l}")
    print(l)
    return l
    
def calculate_ex2(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    res = []
    for line in lines:
        line = replaceAlphaStrings(l=line)
        #print(line)
        dig = []
        for ch in line:
            if ch.isdigit():
                dig.append(ch)
                #print(ch)
        d = int(dig[0])*10
        d += int(dig[-1])
        print(d)
        print("-----")
        res.append(d)
    sum = 0
    for r in res:
        sum += int(r)
    return sum

if __name__ == "__main__":
    res1 = calculate_ex1("input.txt")
    res2 = calculate_ex2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")
