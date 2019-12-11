// Build an array of a range of numbers.
function range(startAt, endAt) {
  const size = endAt - startAt + 1;
  return [...Array(size).keys()].map(i => i + startAt);
}

// Flatten a 2D array into a 1D array.
function flatten(arr) {
  return [].concat(...arr);
}

// Build an array of coordinates for all neighbours of target coordinate: xPos, yPos
function neighbours(xPos, yPos, numCols, numRows) {
  // Ensure that we don't look for neighbours beyond the edges.
  const startX = Math.max(0, xPos - 1);
  const endX = Math.min(numCols - 1, xPos + 1);
  const startY = Math.max(0, yPos - 1);
  const endY = Math.min(numRows - 1, yPos + 1);

  // Collect target position and it's nine neighbours into a 2D array of [x, y] coordinates.
  const allPositions = range(startY, endY).map(y => range(startX, endX).map(x => [x, y]));

  return flatten(allPositions) // Flatten into a 1D array of [x, y] coordinates.
    .filter(([x, y]) => x !== xPos || y !== yPos); // We only want the neighbours, not the target.
}

// Returns the number of neighbouring mines for target position: x, y
function neighbouringMineCount(x, y, minefield) {
  if (minefield[y].charAt(x) === '*') return '*'; // We only count neighbours of empty spaces.

  const [height, width] = [minefield.length, minefield[0].length];

  return neighbours(x, y, width, height) // Find all the neighbours of this position.
    .filter(([testX, testY]) => minefield[testY].charAt(testX) === '*') // Only keep the mines.
    .length; // How many mines did we find?
}

// This is the function under test, which annotates a minefield with neighbouring mine counts.
export const annotate = (minefield) => {
  if (minefield.length === 0) return []; // No rows, so no processing required.

  const [maxY, maxX] = [minefield.length - 1, minefield[0].length - 1];

  // Build 2D array of the minefield annotated with neighbouring mine counts.
  const minefieldWithCounts = range(0, maxY).map((y) => {
    return range(0, maxX).map((x) => {
      // If neighbour count is 0, then leave space character.
      return neighbouringMineCount(x, y, minefield) || ' ';
    });
  });

  return minefieldWithCounts.map(row => row.join('')); // Assemble back into 1D array of strings.
}
