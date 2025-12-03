mod ex1 {
    use regex::Regex;

    use std::error::Error;
    use std::fs::File;
    use std::io::{BufRead, BufReader};

    fn ex1(filename: &str) -> Result<(u64, u64), Box<dyn Error>> {
        let file = File::open(filename)?;
        let reader = BufReader::new(file);
        let re = Regex::new(r"[A-Z]|\d{1,3}").unwrap();
        let mut global_counter: i64 = 50;
        let mut result_a: u64 = 0;
        let mut result_b: u64 = 0;

        for line in reader.lines() {
            let line = line?; // each line is a result_a<String>
            let matches: Vec<&str> = re
                .find_iter(&line)
                .map(|mat| mat.as_str()) // Get the actual matched string slice
                .collect();

            let mut val: i64 = matches[1].parse().unwrap();
            result_b += val as u64 / 100;
            val = val.rem_euclid(100);
            if matches[0] == "L" {
                // zero is an special case, if we are 0 w
                if global_counter > 0 && val >= global_counter {
                    result_b += 1;
                }
                global_counter -= val;
            } else if matches[0] == "R" {
                if val + global_counter > 99 {
                    result_b += 1;
                }
                global_counter += val;
            } else {
                return Err("Instruction not supported - expecting L or R".into());
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
            Ok((a, b)) => println!("Ex2025_1 result a: {} and b: {}", a, b),
            Err(e) => eprintln!("Ex2025_1 error: {e}"),
        }
    }
}

mod ex2 {

    use regex::Regex;
    use std::error::Error;
    use std::fs;
    use std::io::{BufRead, BufReader};

    fn ex2(filename: &str) -> Result<(u64, u64), Box<dyn Error>> {
        let ex_input = fs::read_to_string(filename)?;

        // Compile regex
        let re = Regex::new(r"(\d+)\s*-\s*(\d+)").unwrap();

        // Iterate over all matches
        for cap in re.captures_iter(&ex_input) {
            let left = &cap[1];
            let right = &cap[2];
            println!("{} - {}", left, right);
        }

        Ok((0, 0))
    }

    pub fn show_result_as() {
        match ex2("./src/ex2_input.txt") {
            Ok((a, b)) => println!("Ex2025_2 result a: {} and b: {}", a, b),
            Err(e) => eprintln!("Ex2025_2 error: {e}"),
        }
    }
}

mod ex3 {
    use std::error::Error;
    use std::fs::File;
    use std::io::{BufRead, BufReader};

    fn ex3(filename: &str) -> Result<(u64, u64), Box<dyn Error>> {
        let mut a: u64 = 0;
        let file = File::open(filename)?;
        let reader = BufReader::new(file);

        let mut b: [char; 2];

        for line in reader.lines() {
            let chars: Vec<char> = line?.chars().collect(); // each line is a result_a<String>

            let mut max_c: char = '0';
            let mut max_c_ix = 0;
            for ix in 0..chars.len() - 1 {
                let c = chars[ix];
                if c > max_c {
                    max_c = c;
                    max_c_ix = ix + 1;
                }
            }

            let mut second_max_c: char = '0';
            for ix in max_c_ix..chars.len() {
                let c = chars[ix];
                if c > second_max_c {
                    second_max_c = c;
                }
            }
            println!("{} - {}", max_c, second_max_c);
            a += (max_c.to_digit(10).unwrap() * 10 + second_max_c.to_digit(10).unwrap()) as u64;
        }

        Ok((a, 0))
    }

    pub fn show_result_as() {
        match ex3("./src/ex3_input.txt") {
            Ok((a, b)) => println!("Ex2025_3 result a: {} and b: {}", a, b),
            Err(e) => eprintln!("Ex2025_3 error: {e}"),
        }
    }
}

fn main() {
    //ex1::show_result_as();
    //ex2::show_result_as();
    ex3::show_result_as();
}

// min - max

// num_char_min
// num_char_max

// if num_char_min < 3
//     check if [11,22,33,44,55,66,77,88,99]
// if
