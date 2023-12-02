


def calculate_ex1(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    sum = 0
    for line in lines:
        dig = []
        for ch in line:
            if ch.isdigit():
                dig.append(ch)
        sum += int(dig[0])*10
        sum += int(dig[-1])

    return sum


def replaceAlphaStrings(l):
    numbers_alpha = {"one" : '1', "two": '2', "three": '3', 
                    "four": '4', "five": '5', "six" : '6', 
                    "seven" : '7', "eight" : '8', "nine" : '9'}
    print(l)
    indexes= []
    dic = {}
    for n in numbers_alpha: 
        ix = 0
        while True:  
            ix = l.find(n, ix)     
            if ix == -1:
                break
            indexes.append(ix)
            dic[ix]= n
            print (n)
            ix+=len(n)
    
    for idx_print in indexes:
        print(f"indexes: {idx_print}")
   
    idx_list = [index for index in indexes if index > -1]
    if len(idx_list) > 0:
        first = min(idx_list)
        last = max(idx_list)
        print(f"min: {first} min text: {dic[first]} number {numbers_alpha[dic[first]]}")
        l = l.replace(dic[first], numbers_alpha[dic[first]])
        print(f"max: {last}  man text: {dic[last]} number {numbers_alpha[dic[last]]}")
        l = l.replace(dic[last], numbers_alpha[dic[last]])
    else:
        print(f"Line no alpha num: {l}")
    print(l)
    return l
    
def calculate_ex2(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    sum = 0
    for line in lines:
        line = replaceAlphaStrings(l=line)
        #print(line)
        dig = []
        for ch in line:
            if ch.isdigit():
                dig.append(ch)
                #print(ch)
        sum += int(dig[0])*10
        sum += int(dig[-1])
        print(int(dig[0])*10 + int(dig[-1]))
        print("-----")

    return sum

if __name__ == "__main__":
    res1 = calculate_ex1("input.txt")
    res2_sample = calculate_ex2("input_sample_ex2.txt")
    res2 = calculate_ex2("input.txt")
    print(f"ex1: {res1}, ex2 sample: {res2_sample} res2: {res2}")
