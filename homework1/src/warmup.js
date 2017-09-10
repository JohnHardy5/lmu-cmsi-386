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
  const arr = [];
  let value = 0;
  let exp = 0;
  let nextvalue = 0;
  while (value < limit && nextvalue <= limit) {
    value = base ** exp;
    arr.push(value);
    callback(value);
    nextvalue = base ** (exp + 1);
    exp += 1;
  }
  return powers;
}

function* powersGenerator(base, limit) {
  let currentPower = 0;
  let currentValue = base ** currentPower;
  while (currentValue <= limit) {
    yield currentValue;
    currentPower += 1;
    currentValue = base ** currentPower;
  }
}

function say(string) {
  if (string === undefined) {
    return '';
  }
  return string;
}

function interleave(...args) {
  const result = [];
  const numItems = (args[0].length + args.length) - 1;
  for (let argumentsPos = 0; argumentsPos < numItems; argumentsPos += 1) {
    const isEven = argumentsPos % 2 === 0;
    const isInArray = argumentsPos < args[0].length;
    const isInArgs = argumentsPos < args.length - 1;
    const isLastInArray = argumentsPos === args[0].length && argumentsPos !== 0;
    const isLastInArgs = argumentsPos === args.length - 1;
    if (isEven) {
      console.log("Is even.");
      if (isLastInArray) {
        result.push(args[0][argumentsPos - (args.length - 1)]);
      } else if (isInArray && isInArgs) {
        result.push(args[0][argumentsPos / 2]);
      } else if (isInArray && !isInArgs) {
        result.push(args[0][argumentsPos - (args.length - 1)]);
      } else if (isInArgs && !isInArray) {
        result.push(args[argumentsPos - (args[0].length - 1)]);
      }
    } else if (!isEven) {
      console.log("Is odd.");
      if (isLastInArgs) {
        result.push(args[argumentsPos - (args[0].length - 1)]);
      } else if (isInArgs && isInArray) {
        result.push(args[Math.ceil(argumentsPos / 2)]);
      } else if (isInArgs && !isInArray) {
        result.push(args[argumentsPos - (args[0].length - 1)]);
      } else if (isInArray && !isInArgs) {
        console.log("Going to push: " + args[0][argumentsPos - (args.length - 1)]);
        result.push(args[0][argumentsPos - (args.length - 1)]);
      }
    }
  }
  return result;
}

module.exports = {
  change,
  stripQuotes,
  scramble,
  powers,
  powersGenerator,
  say,
  interleave,
};
