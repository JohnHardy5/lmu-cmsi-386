const {
  change, stripQuotes, scramble, say, powers, interleave,
  powersGenerator, cylinder, makeCryptoFunctions, randomName,
} = require('../src/warmup');

require('should'); // eslint-disable-line import/no-extraneous-dependencies

// Helper for the scramble tests
function anagramsOfEachOther(s, t) {
  return s.split('').sort().join('') === t.split('').sort().join('');
}

// Helper for testing the callbacky problems
function generatorToArray(generator, ...args) {
  const result = [];
  generator(...args, x => result.push(x));
  return result;
}

describe('change', () => {
  it('handles zero', () => {
    change(0).should.eql([0, 0, 0, 0]);
  });

  it('computes answers for small integer values fine', () => {
    change(97).should.eql([3, 2, 0, 2]);
    change(8).should.eql([0, 0, 1, 3]);
    change(250).should.eql([10, 0, 0, 0]);
    change(144).should.eql([5, 1, 1, 4]);
    change(97).should.eql([3, 2, 0, 2]);
  });

  it('handles large values', () => {
    // This test only passes if the solution is efficient
    change(100000000000).should.eql([4000000000, 0, 0, 0]);
  });

  it('throws the proper exception for negative arguments', () => {
    (() => change(-50)).should.throw(RangeError);
  });
});

describe('stripQuotes', () => {
  it('works on the empty string', () => {
    stripQuotes('').should.eql('');
  });

  it('strips quotes properly for non-empty strings', () => {
    stripQuotes('Hello, world').should.eql('Hello, world');
    stripQuotes('"\'').should.eql('');
    stripQuotes('a"""\'\'"z').should.eql('az');
  });
});

describe('scramble', () => {
  it('scrambles properly', () => {
    ['a', 'rat', 'JavaScript testing', '', 'zzz', '^*^*)^▱ÄÈËɡɳɷ'].forEach(s =>
      anagramsOfEachOther(s, scramble(s)).should.be.true);
  });

  it('is really random (produces all permutations)', () => {
    const possibilities = new Set('ABC ACB BAC BCA CAB CBA'.split(' '));
    for (let i = 0; i < 200; i += 1) {
      possibilities.delete(scramble('ABC'));
    }
    possibilities.size.should.eql(0);
  });
});
