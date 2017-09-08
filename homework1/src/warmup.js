function change(amount){
	if(amount < 0){
		throw new RangeError('negative value')
	}
	let result = [];
	let remaining = amount;
	[25, 10, 5, 1].forEach(coin => {
		result.push(Math.floor(remaining / coin))
		remaining %= coin
	})
	return result
}

function stripQuotes(arg){
	let badchars = ['`', '"', '\'' ];
	let newstring = "";
	for(let i = 0; i < arg.length; i++){
		if(!badchars.includes(arg.charAt(i))){
			newstring += arg.charAt(i)
		}
	}
	return newstring
}

	module.exports = {
	change,
	stripQuotes,
	}
