function change(amount){
	if(amount < 0){
		throw new RangeError('negative value')
	}
	let result = [];
	let remaining = amount;
	[25, 10, 5, 1].forEach(coin => {
		result.push(Math.floor(remaining / coin))
		remaining %= coin;
	})
	return result
}

	module.exports = {
	change,
	}
