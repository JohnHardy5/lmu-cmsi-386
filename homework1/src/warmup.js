// This is homework 1 written by John Hardy and Jordan Sanders

function change(amount) {
  if (amount < 0) {
    throw new RangeError('amount cannot be negative');
  }
  let amountRemaining = amount;
  const coins = [25, 10, 5, 1];
  const result = [0, 0, 0, 0];
  for (let i = 0; i < coins.length; i += 1) {
    result[i] = Math.floor(amountRemaining / coins[i]);
    amountRemaining %= coins[i];
  }
  return result;
}

module.exports = {
  change,
};
