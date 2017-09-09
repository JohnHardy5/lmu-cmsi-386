// This is homework 1 written by John Hardy and Jordan Sanders

function change(amount) {
  if (amount < 0) {
    throw new RangeError('amount cannot be negative');
  }
  const result = [];
  let remaining = amount;
  [25, 10, 5, 1].forEach((coin) => {
    result.push(Math.floor(remaining / coin));
    remaining %= coin;
  });
  return result;
}

function stripQuotes(arg) {
  const badchars = ['`', '"', '\''];
  let newstring = '';
  for (let i = 0; i < arg.length; i += 1) {
    if (!badchars.includes(arg.charAt(i))) {
      newstring += arg.charAt(i);
    }
  }
  return newstring;
}

function scramble(stringarg) {
  const stringarray = [...stringarg];
  return stringarray.charAt(Math.random(0, stringarray.length)) + scramble(stringarray.substring(0, stringarray.length - 1));
}

module.exports = {
  change,
  stripQuotes,
  scramble,
};
