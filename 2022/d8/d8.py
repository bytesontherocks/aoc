

def calculateScoreEx1(input_file_name):
    
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()       

        # calculate edges
        num_of_ch_in_ln=len(lines[0])
        num_of_lines=len(lines)
        num_trees_visible=num_of_ch_in_ln*2+num_of_lines*2-4#4 trees are counted twice

        # create columns
        columns=[]
       
        for ch_ix in range(0,len(lines[0])):
            columns.append([])
            for ln in range(0,len(lines)):
                columns[ch_ix].append(lines[ln][ch_ix])
        
        # work out visibility
        for ln in range(1,len(lines)-1):
            for ch_ix in range(1,len(lines[0])-1):
                el=lines[ln][ch_ix]
                left=lines[ln][:ch_ix]
                right=lines[ln][ch_ix+1:]
                up=columns[ch_ix][:ln]
                down=columns[ch_ix][ln+1:]
                vis=False
                if max(list(left))<el:
                    vis=True
                elif max(list(right))<el:
                    vis=True
                elif max(list(up))<el:
                    vis=True
                elif max(list(down))<el:
                    vis=True

                if vis==True:
                    num_trees_visible+=1            

    return num_trees_visible

def calculateScoreEx2(input_file_name):    
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()       

        # create columns
        columns=[]
       
        for ch_ix in range(0,len(lines[0])):
            columns.append([])
            for ln in range(0,len(lines)):
                columns[ch_ix].append(lines[ln][ch_ix])
        
        # work out visibility
        best_tree=[]
        for ln in range(1,len(lines)-1):
            for ch_ix in range(1,len(lines[0])-1):
                el=lines[ln][ch_ix]
                left=lines[ln][:ch_ix]
                right=lines[ln][ch_ix+1:]
                up=columns[ch_ix][:ln]
                down=columns[ch_ix][ln+1:]
                
                ql=0
                for l in reversed(list(left)):
                    ql+=1
                    if l>=el:
                        break
                qr=0
                for r in list(right):
                    qr+=1
                    if r>=el:
                        break
                qu=0
                for u in reversed(list(up)):
                    qu+=1
                    if u>=el:
                        break
                qd=0
                for d in list(down):
                    qd+=1
                    if d>=el:
                        break
                tree_q=ql*qr*qu*qr  
                best_tree.append(tree_q) 

        best_tree.sort()

    return best_tree[-1]

if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input_sample.txt")
    print(f"ex1: {res1}, ex2: {res2}")