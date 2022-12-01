
def getElfCalListSorted(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    cal_elfs= [0]
    num_cal = 0
    for line in lines[0:len(lines)-1]:
        if line != "\n":
            num_cal += int(line)
        else:            
            cal_elfs.append(num_cal)
            num_cal = 0
    cal_elfs.sort()
    return cal_elfs

def calculate_ex1(input_file_name):
    cal_elfs = getElfCalListSorted(input_file_name)
    return cal_elfs[len(cal_elfs)-1]
        
    
def calculate_ex2(input_file_name):
    cal_elfs = getElfCalListSorted(input_file_name)
    return cal_elfs[len(cal_elfs)-1] +  cal_elfs[len(cal_elfs)-2] +  cal_elfs[len(cal_elfs)-3]

if __name__ == "__main__":
    res1 = calculate_ex1("input.txt")
    res2 = calculate_ex2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")