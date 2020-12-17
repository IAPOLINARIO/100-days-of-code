
fn log(mut writer: impl std::io::Write, string: String) {
    writeln!(writer, "{}", string).expect("Could not write string.");
}

fn main() {
    let year_input = std::env::args().nth(1);
    process_input(year_input, &mut std::io::stdout());
}

fn process_input(year_input: Option<String>, writer: impl std::io::Write) {
    if let Some(x) = &year_input {
        let parsed_result = x.parse::<i32>();
        match parsed_result {
            Ok(year)    => log(writer, age_converter::format_age_output(year)),
            Err(_err)  => log(writer, "Could not parse your input.".to_string()),
        };
    } else {
        log(writer, "Could not parse your input.".to_string());
    }
}

mod age_converter {
    const YEAR_TO_DAY: i32 = 365;

    fn convert_years_to_days(years: i32) -> i32 {
        years * YEAR_TO_DAY
    }

    pub fn format_age_output(year: i32) -> String {
        format!("Year {0} is equal to {1} days.", 
                year, 
                convert_years_to_days(year))
    }
}

#[test]
fn validate_empty_year() {
    let mut result = Vec::new();
    process_input(None, &mut result);
    assert_eq!(result, "Could not parse your input.\n".as_bytes());
}

#[test]
fn validate_invalid_year() {
    let mut result = Vec::new();
    process_input(Some("invalidNumber".to_string()), &mut result);
    assert_eq!(result, "Could not parse your input.\n".as_bytes());
}

#[test]
fn validate_success() {
    let mut result = Vec::new();
    process_input(Some("20".to_string()), &mut result);
    assert_eq!(result, "Year 20 is equal to 7300 days.\n".as_bytes());
}