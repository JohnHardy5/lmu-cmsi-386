// This is homework 1 written by John Hardy and Jordan Sanders

const crypto = require('crypto');

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
  let newString = arg;
  newString = newString.replace(/"/g, '');
  newString = newString.replace(/\\/g, '');
  newString = newString.replace(/'/g, '');
  return newString;
}

function scramble(arg) {
  if (arg === '') {
    return '';
  }
  const randomElement = Math.floor(Math.random() * arg.length);
  let string = arg.slice(0, randomElement) + arg.slice(randomElement + 1, arg.length);
  string = arg.charAt(randomElement) + scramble(string);
  return string;
}

function powers(base, limit, callback) {
  let value = 0;
  let exp = 0;
  let nextvalue = 0;
  while (value < limit && nextvalue <= limit) {
    value = Math.pow(base, exp);
    callback(value);
    nextvalue = Math.pow(base, (exp + 1));
    exp += 1;
  }
}

function* powersGenerator(base, limit) {
  let currentPower = 0;
  let currentValue = Math.pow(base, currentPower);
  while (currentValue <= limit) {
    yield currentValue;
    currentPower += 1;
    currentValue = Math.pow(base, currentPower);
  }
}

function say(string) {
  if (string === undefined) {
    return '';
  }
  return string;
}

function interleave(...args) {
  const firstArray = args.shift();
  const secondArray = args;
  if (firstArray.length === 0) {
    return secondArray;
  } else if (secondArray.length === 0) {
    return firstArray;
  }
  let result = [];
  let current = 0;
  function hasNext(val, arr) {
    return val + 1 < arr.length;
  }
  do {
    result.push(firstArray.shift());
    result.push(secondArray.shift());
    current += 1;
  } while (hasNext(current, firstArray) && hasNext(current, secondArray));
  result = result.concat(firstArray);
  result = result.concat(secondArray);
  return result;
}

function cylinder(obj) {
  let { radius = 1, height = 1 } = obj;

  const surfaceArea = () =>
    ((2 * (Math.PI) * radius * height) + (2 * (Math.PI) * (radius * radius)));

  const volume = () => ((Math.PI) * (radius * radius) * height);

  const widen = (factor) => {
    radius *= factor;
  };
  const stretch = (factor) => {
    height *= factor;
  };
  const toString = () => `Cylinder with radius ${radius} and height ${height}`;

  return Object.freeze({
    get radius() {
      return radius;
    },
    get height() {
      return height;
    },
    surfaceArea,
    volume,
    widen,
    stretch,
    toString,
  });
}

function makeCryptoFunctions(k, alg) {
  function encrypt(val) {
    const key = crypto.createCipher(alg, k);
    let result = key.update(val, 'utf8', 'hex');
    result += key.update.final('hex');
    return result;
  }

  function decrypt(val) {
    const key = crypto.createDecipher(alg, k);
    let result = key.update(val, 'hex', 'utf8');
    result += key.update.final('utf8');
    return result;
  }

  return [encrypt, decrypt];
}

module.exports = {
  change,
  stripQuotes,
  scramble,
  powers,
  powersGenerator,
  say,
  interleave,
  cylinder,
  makeCryptoFunctions,
};
