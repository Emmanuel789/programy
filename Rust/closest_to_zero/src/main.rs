use std::io;

fn main(){


let mut temperature	= [0,0,0,0,0,0];
let mut i = 0;
let len = temperature.len(); //ilosc elementow tablicy


println!("Insert 6 numbers separated by the enter key");

for mut i in 0..len{

let mut data = String::new();
io::stdin().read_line(&mut data)
		.expect("Wrong data");

		
let data = data.trim().parse()
	.expect("error");
	
	
temperature[i] = data;
//println!("temperature[{}]: {}", i, temperature[i]);
}


	
	

let mut i = 0;
let mut flag = 1;

println!();
let mut min = i32::abs(temperature[0]);

for mut i in 0..len {
	if temperature[i] ==0{
	println!("One of the values is equal to 0");
	flag = 0;
	}
}

if flag!=0{
	for  mut i in 0..len-1 {
	
		let x = i32::abs(temperature[i+1]);

		if min > x {
		//println!("{}", min); //obserwacja zmniejszania sie zmiennej min
		min = temperature[i+1];
		i+=1;
		}
		
		else if min < x{
		i+=1;
		}
	
		else if x==0{
		println!("One of the values is equal to 0");
		break
		}
	
	}



println!("Closest to zero is: {}", min);
}

}
