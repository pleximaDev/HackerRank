'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function getDayName(dateString) {
    let dayName = new Array("Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"), 
    monthName = new Array("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"),
    date = dateString.split("/", 3), 
    tempDate = String(monthName[Number(date[0]) - 1] + " " + date[1] + ", " + date[2]), 
    dateTemp = new Date(tempDate);
    // console.log(monthName[Number(date[1])], date[0], ", ", date[2]);
    return dayName[dateTemp.getDay()];
}


function main() {
    const d = +(readLine());
    
    for (let i = 0; i < d; i++) {
        const date = readLine();
        
        console.log(getDayName(date));
    }
}
