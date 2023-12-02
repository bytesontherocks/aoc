
import re

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
    #print(l)
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
            #print (n)
            ix+=len(n)
    
    #for idx_print in indexes:
    #    print(f"indexes: {idx_print}")
   
    idx_list = [index for index in indexes if index > -1]
    if len(idx_list) > 0:
        first = min(idx_list)
        last = max(idx_list)
        l = re.sub(dic[first],numbers_alpha[dic[first]],l,1)
        l = re.sub(dic[last],numbers_alpha[dic[last]],l, 1)
        # print(f"min: {first} min text: {dic[first]} number {numbers_alpha[dic[first]]}")
        # l = l.replace(dic[first], numbers_alpha[dic[first]])
        # print(f"max: {last}  man text: {dic[last]} number {numbers_alpha[dic[last]]}")
        # l = l.replace(dic[last], numbers_alpha[dic[last]])
    #else:
    #    print(f"Line no alpha num: {l}")
    #print(l)
    return l

def replaceAlphaStringsAlt2(l):
    print(l)
    l = re.sub("one", "1", l)
    l = re.sub("two","2",l)
    l = re.sub("three", "3", l)
    l = re.sub("four","4",l)
    l = re.sub("five", "5", l)
    l = re.sub("six","6",l)
    l = re.sub("seven", "7", l)
    l = re.sub("eight","8",l)
    l = re.sub("nine", "9", l)

    return l

def replaceAlphaStringsAlt3(l):
    numbers_alpha = {"one" : '1', "two": '2', "three": '3', 
                    "four": '4', "five": '5', "six" : '6', 
                    "seven" : '7', "eight" : '8', "nine" : '9'}
    

    finish = False
    ix  =0
    while finish == False:
        for n in numbers_alpha:
            if l.startswith(n, ix) == True:
                l = re.sub(n, numbers_alpha[n], l)
                print(l)
                ix=0
                break
                       
        ix += 1
        if ix >= len(l):
            finish=True
            break
        

    return l
    
    
def calculate_ex2(input_file_name):
    numbers_alpha = {"one" : '1', "two": '2', "three": '3', 
                    "four": '4', "five": '5', "six" : '6', 
                    "seven" : '7', "eight" : '8', "nine" : '9', 
                    "1":"1","2": "2","3":"3","4":"4", "5":"5","6": "6","7":"7","8":"8", "9":"9"}
    f = open(input_file_name, "r")
    lines = f.readlines()
    sum = 0
    for line in lines:
        dig = re.findall("(?=([0-9]|one|two|three|four|five|six|seven|eight|nine))", line)       
        dig_1_10 = numbers_alpha[dig[0]]
        dig_1 = numbers_alpha[dig[-1]]
        sum += int(dig_1_10)*10
        sum += int(dig_1)
        #print(int(dig_1_10)*10 + int(dig_1))
        # print("-----")
        org_line = line
        line = replaceAlphaStrings(l=line)
        #print(line)
        dig_3 = []
        for ch in line:
            if ch.isdigit():
                dig_3.append(ch)
                #print(ch)
        if dig_1_10 != dig_3[0] or dig_1 != dig_3[-1]:
            print(f"Org line {org_line} subs line {line} Error diff {dig_1_10} should be == {dig_3[0]} ##  {dig_1} should be == {dig_3[-1]}]")

    return sum

if __name__ == "__main__":
   # res1 = calculate_ex1("input.txt")
    res2_sample = calculate_ex2("input.txt")
    print(res2_sample)
    #res2 = calculate_ex2("input.txt")
    #print(f"ex1: {res1}, ex2 sample: {res2_sample} res2: {res2}")
