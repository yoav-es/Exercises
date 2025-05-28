import unittest
from snakes_and_ladders import solver, find_snakes_bf, find_ladders


class Tests(unittest.TestCase):
    """Unit tests for the snakes_and_ladders module."""

    def setUp(self) -> None:
        """Set up test boards for each test."""
        self.board1 = [
            [" ", "l", "c", " "],
            [" ", "l", " ", "c"],
            [" ", "l", " ", "c"]
        ]
        self.board2 = [
            [" ", "l", "c", " "],
            [" ", "l", " ", "c"],
            [" ", "l", " ", " "]
        ]
        self.board3 = [
            [" ", "l", " ", " "],
            ["c", " ", " ", "c"],
            ["c", " ", "l", " "],
            ["c", " ", " ", " "]
        ]

    def test_example1(self):
        """Test solver: should reach the end on board1 with step size 2."""
        self.assertTrue(solver(self.board1, 2, (0, 1), (2, 2)))
        """Test solver: should not reach the end on board2 with step size 2."""
    def test_example2(self):
        self.assertFalse(solver(self.board2, 2, (0, 1), (2, 2)))
        """Test solver: should reach the end on board3 with step size 3."""
    def test_example3(self):
        self.assertTrue(solver(self.board3, 3, (0, 2), (3, 1)))
        """Test snake mapping on board1."""
    def test_snakes_map(self):
        expected = {(2, 3): (0, 2)}
        self.assertEqual(find_snakes_bf(self.board1), expected)
        """Test ladder mapping on board1."""
    def test_ladders_map(self):
        expected = {(0, 1): (2, 1)}
        self.assertEqual(find_ladders(self.board1), expected)

    def tearDown(self) -> None:
        """Clean up test boards."""
        del self.board1
        del self.board2
        del self.board3

if __name__ == "__main__":
    unittest.main()