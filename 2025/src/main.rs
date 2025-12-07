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

    fn ex3(filename: &str, num_digits: usize) -> Result<u64, Box<dyn Error>> {
        let mut res: u64 = 0;
        let file = File::open(filename)?;
        let reader = BufReader::new(file);

        for line in reader.lines() {
            let chars: Vec<char> = line?.chars().collect(); // each line is a result_a<String>

            let mut b = vec!['0'; num_digits];

            let mut max_c_ix = 0;

            for dig_ix in (0..=(num_digits - 1)).rev() {
                for ix in max_c_ix..chars.len() - dig_ix {
                    let c = chars[ix];
                    if c > b[dig_ix] {
                        b[dig_ix] = c;
                        max_c_ix = ix + 1;
                    }
                }
            }
            for ix in 0..num_digits {
                res += b[ix].to_digit(10).unwrap() as u64 * 10u64.pow(ix as u32);
            }
        }

        Ok(res)
    }

    pub fn show_result_as() {
        match ex3("./src/ex3_input.txt", 2) {
            Ok(a) => println!("Ex2025_3 result a: {}", a),
            Err(e) => eprintln!("Ex2025_3 error: {e}"),
        }

        match ex3("./src/ex3_input.txt", 12) {
            Ok(b) => println!("Ex2025_3 result b: {}", b),
            Err(e) => eprintln!("Ex2025_3 error: {e}"),
        }
    }
}

mod ex4 {

    use std::error::Error;
    use std::fs::File;
    use std::io::{BufRead, BufReader};

    fn count_forkable_neighbors(grid: &Vec<Vec<char>>, y: usize, x: usize) -> u64 {
        // 8-direction neighbors
        const NEIGHBORS: [(isize, isize); 8] = [
            (-1, -1),
            (-1, 0),
            (-1, 1), // above
            (0, -1),
            (0, 1), // left / right
            (1, -1),
            (1, 0),
            (1, 1), // below
        ];

        let height = grid.len();
        let width = grid[y].len();

        let mut forkable = 0;

        for (dy, dx) in NEIGHBORS {
            let ny = y as isize + dy;
            let nx = x as isize + dx;

            if ny >= 0 && (ny as usize) < height && nx >= 0 && (nx as usize) < width {
                let c = grid[ny as usize][nx as usize];
                forkable += (c == '@') as u64;
            }
        }

        forkable
    }

    fn ex4_<F>(grid: &mut Vec<Vec<char>>, mut action: F) -> u64
    where
        F: FnMut(u64, usize, usize, &mut Vec<Vec<char>>) -> u64,
    {
        let mut result = 0;

        for y in 0..grid.len() {
            for x in 0..grid[y].len() {
                if grid[y][x] != '@' {
                    continue;
                }

                let forkable = count_forkable_neighbors(grid, y, x);

                // Execute the injection lambda
                result += action(forkable, y, x, grid);
            }
        }

        result
    }

    fn ex4(filename: &str) -> Result<(u64, u64), Box<dyn Error>> {
        let file = File::open(filename)?;
        let reader = BufReader::new(file);

        // Load entire file into a 2D mutable char grid
        let mut grid: Vec<Vec<char>> = reader
            .lines()
            .collect::<Result<Vec<_>, _>>()?
            .into_iter()
            .map(|line| line.chars().collect())
            .collect();

        let height = grid.len();
        if height == 0 {
            return Ok((0, 0));
        }

        let mut result_b: u64 = 0;

        let result_a = ex4_(
            &mut grid.clone(),
            |forkable, _, _, _| {
                if forkable < 4 { 1 } else { 0 }
            },
        );

        //exb
        let mut result_b = 0 as u64;
        let mut result_b_prev = 1 as u64;
        while result_b != result_b_prev {
            result_b_prev = result_b;
            result_b += ex4_(&mut grid, |forkable, y, x, grid| {
                if forkable < 4 {
                    grid[y][x] = '.'; // mutate
                    1
                } else {
                    0
                }
            });
        }

        Ok((result_a, result_b))
    }

    pub fn show_result_as() {
        match ex4("./src/ex4_input.txt") {
            Ok((a, b)) => println!("Ex2025_2 result a: {} and b: {}", a, b),
            Err(e) => eprintln!("Ex2025_4 error: {e}"),
        }
    }
}
fn main() {
    //ex1::show_result_as();
    //ex2::show_result_as();
    //ex3::show_result_as();
    ex4::show_result_as();
}

// min - max

// num_char_min
// num_char_max

// if num_char_min < 3
//     check if [11,22,33,44,55,66,77,88,99]
// if
