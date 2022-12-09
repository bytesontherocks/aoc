def getNextLine(lines, ix):
    return lines[ix].split(), ix + 1

def getDirectorySize(tree, dir_id):
    dir=tree[dir_id]
    dir_sz=dir[-1]
    for d in range(0,len(dir)-1):  
        dir_sz += getDirectorySize(tree, dir[d])
    
    return dir_sz

def updateDirPath(ln, dir):
    if ln[1] == "cd" and ln[2].isalpha():
        dir.append(ln[2])
    elif  ln[1] == "cd" and ln[2]=="..":
        dir.pop() # cd ..
    print(dir)
    return dir

    root_dir = dir['/']
    root_dir = [{'a' : [{'e': [584]}, f, g, h]}, b, c, {'d': [j,dl,de, k]}]

    # dir a -> C
    # 14848514 b.txt
    # 8504156 c.dat


def calculateScoreEx1(input_file_name):
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        ln_ix=0 
        root_sz = [] 
        dir = []
        while ln_ix < len(lines):
            ln = lines[ln_ix].split()   
                    

            if ln[1] == "cd":
                acc = 0
                cwd = ln[2]          
                if ln[2] != "..":
                    ln_ix += 2 #ignore ls
                    ln = lines[ln_ix].split()
                    while ln[0] != "$":
                        ln = lines[ln_ix].split()
                        if ln[0].isdigit():
                            acc += int(ln[0])

                        ln_ix+=1 
                        if ln_ix >= len(lines):
                            break                   
                           
                    entry = {}      
                    entry[cwd] = acc
                    dir.append(entry)
                    
                else:        
                    root_sz.append(dir)                        
                    dir = []


            # ln_ix+=1 
            # if ln_ix >= len(lines):
            #     break
           
           
        print(dir)    
            
            
                 





    return 0

def calculateScoreEx2(input_file_name):    
    f = open(input_file_name, "r")
    lines = f.readlines()  
    return 0

if __name__ == "__main__":
    res1 = calculateScoreEx1("input_sample.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")