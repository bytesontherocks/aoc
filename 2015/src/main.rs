mod u {
    // pub fn read_line(filename: &str) -> Result<i64, Box<dyn Error>> {
    //     let file = File::open("input.txt")?;
    //     let mut reader = BufReader::new(file);

    //     let mut line = String::new();

    //     loop {
    //         line.clear();
    //         let n = reader.read_line(&mut line)?; // reads into same buffer

    //         if n == 0 {
    //             break; // EOF
    //         }

    //         print!("{line}");
    //     }

    //     Ok(())
    // }
}

mod ex1 {
    use std::{error::Error, fs};
    fn a(filename: &str) -> Result<i64, Box<dyn Error>> {
        // Read the entire file into a string
        let contents = fs::read_to_string(filename)?;
        let count_up = contents.matches('(').count() as i64;
        let count_down = contents.matches(')').count() as i64;

        Ok(count_up - count_down)
    }

    fn b(filename: &str) -> Result<i64, Box<dyn Error>> {
        let contents = fs::read_to_string(filename)?;
        let mut count_up: i64 = 0;
        let mut count_down: i64 = 0;

        for c in contents.chars() {
            match c {
                '(' => count_up += 1,
                ')' => count_down += 1,
                _ => continue, // ignore other characters
            }

            // first time the floor goes below 0 => return 1-based position
            if (count_up - count_down) < 0 {
                return Ok(count_up + count_down);
            }
        }

        Err("basement (-1) never reached".into())
    }

    pub fn show_results() {
        match a("./src/ex1.txt") {
            Ok(v) => println!("Ex2015_1A result: {v}"),
            Err(e) => eprintln!("Ex2015_1A error: {e}"),
        }
        match b("./src/ex1.txt") {
            Ok(v) => println!("Ex2015_1B result: {v}"),
            Err(e) => eprintln!("Ex2015_1B error: {e}"),
        }
    }
}
mod ex2 {
    use std::error::Error;
    use std::fs::File;
    use std::io::{BufRead, BufReader};

    fn a(filename: &str) -> Result<(i64, i64), Box<dyn Error>> {
        let file = File::open(filename)?;
        let reader = BufReader::new(file);

        let mut wrapping_papper: i64 = 0;
        let mut ribbon: i64 = 0;
        for line in reader.lines() {
            let line = line?; // each line is a Result<String>
            let mut parts = line.split('x');

            let l: i64 = parts.next().unwrap().parse().unwrap();
            let w: i64 = parts.next().unwrap().parse().unwrap();
            let h: i64 = parts.next().unwrap().parse().unwrap();

            wrapping_papper += 2 * l * w + 2 * w * h + 2 * h * l;

            let mut slack: [i64; 3] = [l, w, h];
            slack.sort();
            wrapping_papper += slack[0] * slack[1];
            ribbon += slack[0] * 2 + slack[1] * 2 + slack.iter().copied().product::<i64>();
        }

        Ok((wrapping_papper, ribbon))
    }

    pub fn show_results() {
        match a("./src/ex2.txt") {
            Ok((a, b)) => println!("ex2a result: {a}, ex2b {b}"),
            Err(e) => eprintln!("ex1a error: {e}"),
        }
    }
}
fn main() {
    ex1::show_results();
    ex2::show_results();
}
