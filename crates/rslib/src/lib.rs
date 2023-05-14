#[no_mangle]
pub extern "C" fn hello() {
    println!("Hello from rust");
}

#[no_mangle]
pub extern "C" fn cube(i: i32) -> i32 {
    i * i * i
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn cube_test() {
        assert_eq!(cube(3), 27)
    }
}
