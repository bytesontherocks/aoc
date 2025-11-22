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
mod ex3 {
    use std::collections::HashMap;
    use std::{error::Error, fs};

    fn a(filename: &str) -> Result<usize, Box<dyn Error>> {
        // Read the entire file into a string
        let contents = fs::read_to_string(filename)?;
        let mut x: i32 = 0;
        let mut y: i32 = 0;

        let mut count: HashMap<(i32, i32), i32> = HashMap::new();
        count.insert((x, y), 1);

        for c in contents.chars() {
            match c {
                '^' => x += 1,
                'v' => x -= 1,
                '>' => y += 1,
                '<' => y -= 1,
                _ => continue, // ignore other characters
            }
            *count.entry((x, y)).or_insert(1) += 1;
        }

        Ok(count.len())
    }
    fn b(filename: &str) -> Result<usize, Box<dyn Error>> {
        // Read the entire file into a string
        let contents = fs::read_to_string(filename)?;
        let mut x: i32 = 0;
        let mut y: i32 = 0;
        let mut x2: i32 = 0;
        let mut y2: i32 = 0;
        let mut moves: i32 = 1;
        let mut count: HashMap<(i32, i32), i32> = HashMap::new();
        count.insert((x, y), 1);

        for c in contents.chars() {
            // Choose which Santa moves
            let (xpos, ypos) = if moves & 1 == 1 {
                (&mut x, &mut y)
            } else {
                (&mut x2, &mut y2)
            };

            // Apply move
            match c {
                '^' => *xpos += 1,
                'v' => *xpos -= 1,
                '>' => *ypos += 1,
                '<' => *ypos -= 1,
                _ => {
                    moves += 1;
                    continue;
                } // skip invalid chars but still alternate
            }

            // Count visit
            *count.entry((*xpos, *ypos)).or_insert(1) += 1;

            moves += 1;
        }

        Ok(count.len())
    }

    pub fn show_results() {
        match a("./src/ex3.txt") {
            Ok(v) => println!("a result: {v}"),
            Err(e) => eprintln!("a error: {e}"),
        }

        match b("./src/ex3.txt") {
            Ok(v) => println!("b result: {v}"),
            Err(e) => eprintln!("b error: {e}"),
        }
    }
}

mod ex4 {
    use md5;
    use std::error::Error;

    fn a(prefix: &str, target: &str) -> Result<u32, Box<dyn Error>> {
        for num_cand in 0u32..=u32::MAX {
            let candidate = format!("{}{}", prefix, num_cand.to_string());

            let digest = format!("{:x}", md5::compute(candidate.as_bytes()));
            if digest.starts_with(&target) {
                println!("{}", digest);
                return Ok(num_cand);
            }
        }

        Err("no candidate met the requiments".into())
    }

    pub fn show_results() {
        match a("iwrupvqb", "00000") {
            Ok(a) => println!("ex4a result: {a}"),
            Err(e) => eprintln!("ex4a error: {e}"),
        }
        match a("iwrupvqb", "000000") {
            Ok(a) => println!("ex4b result: {a}"),
            Err(e) => eprintln!("ex4b error: {e}"),
        }
    }
}

fn main() {
    ex1::show_results();
    ex2::show_results();
    ex3::show_results();
    ex4::show_results();
}
