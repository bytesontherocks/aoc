

def calculateScoreEx1(input_file_name):
    
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()       

        # calculate edges
        num_of_ch_in_ln=len(lines[0])
        num_of_lines=len(lines)
        print(f"chars in ln {num_of_ch_in_ln}, lines {num_of_lines}")
        num_trees_visible=num_of_ch_in_ln*2+num_of_lines*2-4#4 trees are counted twice
        print(f"trees at the edge {num_trees_visible}")

        # create columns
        columns=[]
       
        for ch_ix in range(0,len(lines[0])):
            columns.append([])
            for ln in range(0,len(lines)):
                columns[ch_ix].append(lines[ln][ch_ix])
        
        print("columns")
        print(columns)
       
        # work out visibility
        for ln in range(1,len(lines)-1):
            for ch_ix in range(1,len(lines[0])-1):
                el=lines[ln][ch_ix]
                #print(lines[ln][ch_ix])
                left=lines[ln][:ch_ix]
                right=lines[ln][ch_ix+1:]
                up=columns[ch_ix][:ln]
                down=columns[ch_ix][ln+1:]
                #print(f"left {left}, right {right}")
                #print(f"up {up}, down {down}")
                vis=False
                print(max(list(left)))
                if max(list(left))>el:
                    vis=True
                elif max(list(right))>el:
                    vis=True
                elif max(list(up))>el:
                    vis=True
                elif max(list(down))>el:
                    vis=True

                if vis==True:
                    num_trees_visible+=1            

    return num_trees_visible

def calculateScoreEx2(input_file_name):    
  
    return 0

if __name__ == "__main__":
    res1 = calculateScoreEx1("input_sample.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")