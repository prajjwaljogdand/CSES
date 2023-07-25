#[allow(unused_imports)]
#[allow(dead_code)]
#[allow(unused)]


use std::io::{BufWriter, stdin, stdout, Write};
use std::str;
use std::io::BufRead;
 
struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitWhitespace<'static>,
}
impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self { reader, buf_str: vec![], buf_iter: "".split_whitespace() }
    }
    fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader.read_until(b'\n', &mut self.buf_str).expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_whitespace())
            }
        }
    }
}

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {

    let n:i32 = scan.token::<i32>();
    let m:i32 = scan.token::<i32>();
    let k:i32 = scan.token::<i32>();

    let mut desired_size:Vec<i32> = (0..n).map(|_| scan.token()).collect();
    let mut apart_size:Vec<i32> = (0..m).map(|_| scan.token()).collect();
    let mut count  = 0 ;
    for apt in  apart_size.into_iter() {
        for desir in desired_size.into_iter() {
            if desir < apt + k && desir > apt - k {
                let elem = desir; 
                let elem2 = apt;
                desired_size.remove(desired_size.iter().position(|x| *x == elem).expect("not found"));
                apart_size.remove(apart_size.iter().position(|x| *x == elem2).expect("not found"));
                count += 1;
            }
        }
    }

    writeln!(w,"{} {} {}",n,m,count).ok();


}
 
fn main() {
    let (stdin, stdout) = (stdin(),stdout());
    let mut scan = Scanner::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());
    solve(&mut scan, &mut out);
}