
var readlineSync = require('readline-sync');
var value;
const days = 365;
var years = readlineSync.question('How many years do you want to convert to days?? ');
value = (years * days);
console.log(years+' YEARS ARE EQUAL TO '+value+' DAYS!');


module.exports = function(years, days ) {
    return days*years;
}

// function convert(days , yars) {

// }
