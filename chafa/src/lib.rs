pub fn add(x: u8, y: u8) -> u8 {
    x + y
}

#[cfg(test)]
mod tests {
    use crate::add;

    #[test]
    fn test() {
        assert_eq!(add(1, 1), 2);
    }
}
