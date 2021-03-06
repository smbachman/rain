import {floatEqual} from './comparison.js';
import * as T from './tuples.js';

export function matrix(size, ...args) {
  let m = new Array(size);

  let i = 0;

  for (let row = 0; row < size; row++) {
    m[row] = new Array(size);
    for (let column = 0; column < size; column++) {
      m[row][column] = args[i++] || 0;
    }
  }

  return m;
}

export function equal(a, b) {
  for (let row = 0; row < a.length; row++) {
    for (let column = 0; column < a[0].length; column++) {
      if (!floatEqual(a[row][column], b[row][column])) {
        return false;
      }
    }
  }
  
  return true;
}

export function multiply(a, b) {
  let m = matrix(4);
  
  for (let row = 0; row < a.length; row++) {
    for (let column = 0; column < a[0].length; column++) {
      m[row][column] = 
          a[row][0] * b[0][column]
        + a[row][1] * b[1][column]
        + a[row][2] * b[2][column]
        + a[row][3] * b[3][column];
    }
  }
  
  return m;
}

const multiplyMatrix = multiply;

export function multiplyTuple(m, t) {
  let tm = matrix(4,
    t.x, 0, 0, 0, 
    t.y, 0, 0, 0,
    t.z, 0, 0, 0,
    t.w, 0, 0, 0);
  
  let result = multiplyMatrix(m, tm);
  
  return T.tuple(result[0][0], result[1][0], result[2][0], result[3][0]);
}

export const identity = matrix(4,
  1, 0, 0, 0,
  0, 1, 0, 0,
  0, 0, 1, 0,
  0, 0, 0, 1);
  
export function transpose(m) {
  let result = matrix(4);
  
  for (let row = 0; row < m.length; row++) {
    for (let column = 0; column < m[0].length; column++) {
      result[row][column] = m[column][row];
    }
  }
  
  return result;
}

export function submatrix(m, rowToExclude, columnToExclude) {
  let result = matrix(m.length - 1);
  
  for (let row = 0; row < m.length; row++) {
    let resultRow, resultColumn;
    if (row !== rowToExclude) {
      resultRow = row > rowToExclude ? row - 1 : row;
      for (let column = 0; column < m[0].length; column++) {
        if (column !== columnToExclude) {
          resultColumn = column > columnToExclude ? column - 1 : column;
          result[resultRow][resultColumn] = m[row][column];
        }
      }
    }
  }
  
  return result;
}

export function minor(m, row, column) {
  return determinant(submatrix(m, row, column));
}

export function cofactor(m, row, column) {
  let mr = minor(m, row, column);  
  return ((row + column) % 2 === 0) ? mr : -mr;
}

export function determinant(m) {
  let d = 0;
  
  if (m.length === 2) {
    d = m[0][0] * m[1][1] - m[0][1] * m[1][0];
  } else {
    for (let column = 0; column < m.length; column++) {
      d += m[0][column] * cofactor(m, 0, column);
    } 
  }
  
  return d;
}

export function isInvertible(m) {
  return determinant(m) !== 0;
}

export function inverse(m) {
  if (!isInvertible(m)) throw new Error('cannot invert');
  
  let m2 = matrix(m.length);
  let d = determinant(m);
  
  for (let row = 0; row < m.length; row++) {
    for (let column = 0; column < m.length; column++) {
      let c = cofactor(m, row, column);
      
      m2[column][row] = c / d;
    }
  }
  
  return m2;
}
