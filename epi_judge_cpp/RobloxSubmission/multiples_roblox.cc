#include <iostream>
#include <list>
#include <numeric>
#include <vector>

/**
 * Represents a number.
 */
class Number {
public:
  /**
   * @brief Construct a new Number object
   *
   * @param val Intialize with a digit
   *
   * @note val <= 9
   */
  Number(int val) { 
    _numStr.resize(1); 
    _numStr[0] = (char('0' + val)); 
  }
  Number() {}
  ~Number() {
    _numStr.clear();
    _numStr.shrink_to_fit();
  }

  Number(const Number &o) : _numStr(o._numStr) {}
  Number(Number &&o) : _numStr(std::move(o._numStr)) {}
  Number &operator=(Number const &other) {
    _numStr = other._numStr;
    return *this;
  }

  Number &operator=(Number &&other) {
    _numStr = std::move(other._numStr);
    return *this;
  }

  /**
   * @brief Multiplication operation on the existing number.
   *
   * @param val
   */
  void multiply(int val) {
    auto iter = _numStr.begin();
    int carry = 0;
    while (iter != _numStr.end()) {
      int curr = (*iter - '0') * val;
      curr += carry;
      *iter = curr % 10 + '0';
      carry = curr / 10;
      ++iter;
    }
    if (carry != 0) {
      _numStr.resize(_numStr.capacity() + 1);
      _numStr.push_back(char(carry + '0'));
    }
  }

  /**
   * @brief Return the number of digits in this number.
   *
   * @return int
   */
  int size() const { return _numStr.size(); }

  bool operator<(Number const &b) const {
    // Handle an uninitialized Number with no digits
    if (_numStr.size() == 0 || b.size() == 0) {
      return _numStr.size() == 0 ? false : true;
    } else if (_numStr.size() < b.size()) {
      return true;
    } else if (_numStr.size() > b.size()) {
      return false;
    } else {
      auto iter1 = _numStr.crbegin();
      auto iter2 = b.getRbegin();

      while (iter1 != _numStr.crend() && iter2 != b.getRend() && *iter1 == *iter2) {
        ++iter1;
        ++iter2;
      }

      return *iter1 < *iter2;
    }
  }

  // Friend function to output the number
  friend std::ostream &operator<<(std::ostream &out, const Number &number);

private:
  std::vector<char>::const_reverse_iterator getRbegin() const { return _numStr.crbegin(); }

  std::vector<char>::const_reverse_iterator getRend() const { return _numStr.crend(); }

  /**
   * Digits that represent a number, most significant bit is present at the
   * front. Representing each digit as a character instead of an int helps in
   * saving space required to represent a digit in the number.
   *
   * @note Storage for a result of multiplication for a number
   * with a high number of digits might seem to naturally fit the usecase for an
   * std::list. However a list node in addition to the data in each node also
   * includes 2 pointers to the next and previous nodes which causes memory in
   * efficiency. In addition for the problem at hand, allocaiton of new nodes in
   * the list causes Random memory causes causing a significant degradation in
   * performance when compared to using a vector for the same number of digits.
   */
  std::vector<char> _numStr;
};

std::ostream &operator<<(std::ostream &out, const Number &number) {
  auto iter = number.getRbegin();
  while(iter != number.getRend()) {
    out << *iter;
    ++iter;
  }
  return out;
}

// TODO Remove currNumIdx
std::pair<Number, int>
findMinCandidate(std::vector<long int> const& nextCandidateIdxs,
                 std::vector<long int> const& nextInsertionIdxs,
                 std::vector<std::vector<Number>> &multiples,
                 long int &currNumIdx) {
  int minIdx = 0;
  Number minNumber = Number();
  for (int i = 0; i < nextCandidateIdxs.size(); i++) {
    Number const& nextCandidate = nextCandidateIdxs[i] < nextInsertionIdxs[i]
                                      ? multiples[i][nextCandidateIdxs[i]]
                                      : Number();
    if (nextCandidate < minNumber) {
      minIdx = i;
      minNumber = multiples[i][nextCandidateIdxs[i]];
    }
  }

  return {minNumber, minIdx};
}

// void pruneProcessed(std::vector<std::vector<Number>> &multiples,
//                     std::vector<long int> &nextInsertionIdxs,
//                     std::vector<long int> &nextCandidateIdxs,
//                     long int &currNumIdx) {
//   for (int i = 0; i < multiples.size(); i++) {
//     if (nextInsertionIdxs[i] == multiples[i].capacity()) {
//       long int newReservation = multiples[i].capacity();
//       if (nextCandidateIdxs[i] > (multiples[i].capacity() / 2)) {
//         // std::cout << "Pruning " << i << " of length " << nextCandidateIdxs[i] << " at index " << currNumIdx << std::endl;
//         multiples[i].erase(multiples[i].begin(),
//                            (multiples[i].begin() + nextCandidateIdxs[i]));
//         multiples[i].shrink_to_fit();
//         nextInsertionIdxs[i] -= nextCandidateIdxs[i];
//         nextCandidateIdxs[i] = 0;
//       } else {
//         newReservation *= 2;
//         // std::cout << "Increasing the new reservation to " << newReservation << std::endl;
//       }
//       multiples[i].reserve(newReservation);
//     }
//   }

//   int i = 0;
//   while(i < multiples.size() && nextCandidateIdxs[i] == nextInsertionIdxs[i]) {
//     // // // std::cout << "Vector for " << i  << " will now be empty "<< std::endl;
//     multiples[i].resize(1);
//     multiples[i][0] = Number();
//     nextCandidateIdxs[i] = 0;
//     nextInsertionIdxs[i] = 0;
//     multiples[i].shrink_to_fit();
//     i++;
//   }
// }


std::pair<long int, long int>  insert(std::vector<Number>& multiples,
            long int nextInsertionIdx,
            long int nextCandidateIdx,
            Number nextMultiple) {
  if (nextInsertionIdx == multiples.capacity()) {
    long int newReservation = multiples.capacity();
    if (nextCandidateIdx > (multiples.capacity() / 2)) {
      multiples.erase(multiples.begin(), (multiples.begin() + nextCandidateIdx));
      multiples.shrink_to_fit();
      nextInsertionIdx -= nextCandidateIdx;
      nextCandidateIdx = 0;
    } else {
      newReservation *= 2;
    }
    multiples.resize(newReservation);
  }
  
  multiples[nextInsertionIdx] = nextMultiple;
  ++nextInsertionIdx;

  return {nextInsertionIdx, nextCandidateIdx};
}

long int getMaxReservation(long int n) {
  if (n < 1000) {
    return 10;
  } else if (n < 10000) {
    return 100;
  } else if (n < 1000000) {
    return 1000;
  } else if (n < 1000000) {
    return 10000;
  } else if (n < 10000000) {
    return 100000;
  } else if (n < 100000000) {
    return 1000000;
  } else {
    return 10000000;
  }
}

/**
 * @brief Generate the nth number that can be factored with given list
 * of prime numbers.
 *
 * @param n Nth number.
 * @param primes Vector of prime numbers.
 *
 * @return Nth Number.
 */
Number nthMultiple(long int n, std::vector<int> primes) {
  /*
   * Approach
   *
   * - Maintain a separate vector of Number objects for each prime number. These
   * are the candidate Numbers for finding the next number that is factorable
   * only from the prime numbers.
   * - Find the least number from the first non processed candidate of each
   * vector.
   * - Generate multiples of primes higher than the vector from which the
   * current element was chosen and append it to their respective vectors. This
   * helps in eliminating duplicates in each of the vectors.
   * - Finally pre reserve the individual vectors based on the value n. A basic
   * reservation algorithm is implemented here, but should be tuned to the
   * target. Reserving the vector size prevents costly re allocations when new
   * elements are added to the vector.
   *
   * For instance for primes {2, 3, 5}
   * Initial state
   * multiples[0] - {2}
   * multiples[1] - {3}
   * multiples[2] - {5}
   * nextCandidateIdxs {0,0,0}
   *
   * min(multiples[0][nextCandidateIdx[0]], .. ) is min(2,3,5) = 2
   *
   * multiples[0] - {2, 4}
   * multiples[1] - {3, 6}
   * multiples[2] - {5, 10}
   * nextCandidateIdxs {1,0,0}
   *
   * min(multiples[0][nextCandidateIdx[0]], .. ) is min(4,3,5) = 3
   *
   * multiples[0] - {2, 4}
   * multiples[1] - {3, 6, 9}
   * multiples[2] - {5, 10, 15}
   * nextCandidateIdxs {1,1,0}
   *
   * min(multiples[0][nextCandidateIdx[0]], .. ) is min(4,6,5) = 5
   */

  long int const maxReserved = getMaxReservation(n);
  unsigned int const numPrimes = primes.size();

  // 2-D vector to store the generated multiples of each prime number. The
  // vectors are sorted as each new multiple is added to the back of the vector.
  std::vector<std::vector<Number>> multiples(numPrimes,
                                             std::vector<Number>(maxReserved));
  std::vector<long int> nextCandidateIdxs(numPrimes, 0);
  std::vector<long int> nextInsertionIdxs(numPrimes, 1);

  for (int i = 0; i < primes.size(); i++) {
    multiples[i][0] = Number(primes[i]);
  }

  Number ans(1);
  Number maxSoFar(1);

  // Number of candidates generated that are not processed yet.
  long int unprocessed = primes.size();
  for (long int i = 1; i < n; i++) {
    auto next = findMinCandidate(nextCandidateIdxs, nextInsertionIdxs, multiples, i);
    Number nextNumber = next.first;
    int const nextPrimeNumberIdx = next.second;
    //std::cout << "Next number " << nextNumber << " " << i << std::endl;
    if (i == n - 1) {
      ans = nextNumber;
      break;
    }
    // Increment the index for the next candidate.
    ++nextCandidateIdxs[nextPrimeNumberIdx];

    // One candidate is processed in this iteration.
    --unprocessed;

    // Numbers to be calculated to reach the target.
    long int const remaining = n - i;

    // In order to eliminate duplicate elements being added to the vectors, only
    // add next least number multiplied by higher primes to their respective
    // vectors.
    //
    // For example if the current element is 10(i.e a multiple of 5), this
    // optimization prevents adding 20 and 30 to five's multiples which would
    // have been already been added when elements 4 (4*5 = 20) and 6 (6*5 = 30)
    // were previously processed. 
    int primeIdx = nextPrimeNumberIdx;
    while (primeIdx < primes.size()) {
      Number nextMultiple = nextNumber;
      nextMultiple.multiply(primes[primeIdx]);
      // Optimization - If the number of unprocessed numbers is greater than the
      // remaining numbers to be processed to get to the target, then only add
      // the newly calculated number if it is greater than the max element that
      // is added to all lists at any point in time.
      if (unprocessed >= remaining && maxSoFar < nextMultiple) {
        break;
      }

      maxSoFar = std::max(maxSoFar, nextMultiple);
      auto nextIdxs = insert(multiples[primeIdx], nextInsertionIdxs[primeIdx], nextCandidateIdxs[primeIdx], nextMultiple);
      nextInsertionIdxs[primeIdx] = nextIdxs.first;
      nextCandidateIdxs[primeIdx] = nextIdxs.second;
      ++unprocessed;
      ++primeIdx;
    }
  }

  return ans;
}

// Driver code
int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid number of arguments " << std::endl;
    return -1;
  }
  std::cout << nthMultiple(strtol(argv[1], NULL, 10), {2, 3, 5}) << std::endl;

  return 0;
}