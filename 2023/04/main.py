import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    res = 0
    l_ix = 0
    l_res = []
    for line in lines:
        line_nums = line.split(":")[1]
        winners = [int(i) for i in re.findall("\d+",line_nums.split("|")[0])]
        candidates = [int(i) for i in re.findall("\d+",line_nums.split("|")[1])]
        #print(f"winners: {winners}")
        #print(f"candidates: {candidates}")
        sumo = []
        points = 1
        num_matches= 0
        for c in candidates:
            loc_sum = 0
            for w in winners:
                if c == w:
                    loc_sum += points
                    points *= 2 
                    num_matches += 1
            sumo.append(loc_sum)

        l_res.append(num_matches)
        res += max(sumo)     
    
    print(l_res)

    scraches = []
    for n_l in lines:
        scraches.append(1)
    
    ix=0
    while ix < len(lines):
        
        times = max(0,l_res[ix]>0)*scraches[ix]
        for j in range(times):
            s_ix=ix+1  
            for k in range(l_res[ix]):             
                if s_ix < len(lines):
                    scraches[s_ix]+=1
                    #print(scraches)
                s_ix+=1
        ix +=1

    return res, sum(scraches)
    
if __name__ == "__main__":
    res_sample = calculate_ex("input_sample_ex.txt")
    res = calculate_ex("input.txt")
    print(f"ex sample: {res_sample}, ex: {res}")