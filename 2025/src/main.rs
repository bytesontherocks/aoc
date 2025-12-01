mod ex1 {
    use regex::Regex;

    
 use std::error::Error;
    use std::fs::File;
    use std::io::{BufRead, BufReader};
    

    fn ex1(filename: &str) -> Result<(u64,u64), Box<dyn Error>> {
        let file = File::open(filename)?;
        let reader = BufReader::new(file);
        let re = Regex::new(r"[A-Z]|\d{1,3}").unwrap();
        let mut global_counter: i64 = 50;
        let mut result_a: u64 = 0;
        let mut result_b: u64 = 0;
        let cpy_gc = 0;
        for line in reader.lines() {
            let line = line?; // each line is a result_a<String>
            let matches: Vec<&str> = re.find_iter(&line)
                .map(|mat| mat.as_str()) // Get the actual matched string slice
                .collect();
            
            let mut  val:i64 = matches[1].parse().unwrap();
            result_b += val as u64 /100;
            val = val.rem_euclid(100);
            if matches[0] == "L" {               

                if global_counter > 0  && val >= global_counter {
                    result_b +=1;
                }
                global_counter -= val;

            } else if matches[0] == "R" {           

                if val + global_counter > 99 {
                    result_b +=1;
                }
                global_counter += val;
            } else {
                return Err("Instruction not supported - expecting L or R".into())
            }

            global_counter = global_counter.rem_euclid(100);

            if global_counter == 0 {
                result_a += 1;
            }
        }
        Ok((result_a, result_b))
    }

     pub fn show_result_as() {
        match ex1("./src/ex1_input.txt") {
            Ok((a,b)) => println!("Ex2025_1A result a: {} and b: {}", a, b),
            Err(e) => eprintln!("Ex2025_1A error: {e}"),
        }
        // match b("./src/ex1_input.txt") {
        //     Ok(v) => println!("Ex2025_1B result_a: {v}"),
        //     Err(e) => eprintln!("Ex2025_1B error: {e}"),
        // }
    }
}


fn main() {
    ex1::show_result_as();
}
