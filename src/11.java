import java.util.*;
import java.io.*;

class Problem {
    // Returns whether a seat in this direction is occupied
    // (Part 2 only)
    private static int isOccup(ArrayList<char[]> grid, int rows, int cols, int i, int j, int dx, int dy) {
        while (true) {
            i += dy;
            j += dx;

            if (i < 0 || j < 0 || i >= rows || j >= cols) break;

            if (grid.get(i)[j] == '#')
                return 1;
            if (grid.get(i)[j] == 'L')
                return 0;
        }

        return 0;
    }

    public static void main(String[] args) {
        try {
            boolean part1 = false;

            ArrayList<char[]> grid1 = new ArrayList<>();
            ArrayList<char[]> grid2 = new ArrayList<>();

            File f = new File("/dev/stdin");
            Scanner reader = new Scanner(f);
            while (reader.hasNextLine()) {
                String data = reader.nextLine();

                grid1.add(data.toCharArray());
                grid2.add(data.toCharArray());
            }

            int rows = grid1.size();
            int cols = grid1.get(0).length;

            boolean changes = true;
            boolean use1 = true;

            // To debug
            int rounds = 0;
            while (true) {
                changes = false;
                ArrayList<char[]> first = use1 ? grid1 : grid2;
                ArrayList<char[]> second = use1 ? grid2 : grid1;

                // O(N^2)
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        int nOccup = 0;

                        if (part1) {
                            // Count occupied seats
                            for (int dx = 0; dx < 3; ++dx) {
                                for (int dy = 0; dy < 3; ++dy) {
                                    if (!(dx == 1 && dy == 1) &&
                                            i - 1 + dy >= 0 && i - 1 + dy < rows &&
                                            j - 1 + dx >= 0 && j - 1 + dx < cols) {
                                        if (first.get(i - 1 + dy)[j - 1 + dx] == '#')
                                            ++nOccup;
                                        }
                                }
                            }

                            if (first.get(i)[j] == 'L') {
                                second.get(i)[j] = nOccup == 0 ? '#' : 'L';
                            }
                            else if (first.get(i)[j] == '#') {
                                second.get(i)[j] = nOccup < 4 ? '#' : 'L';
                            } else {
                                second.get(i)[j] = '.';
                            }
                        } else {
                            // O(N)
                            nOccup += isOccup(first, rows, cols, i, j, 0, 1);
                            nOccup += isOccup(first, rows, cols, i, j, 0, -1);
                            nOccup += isOccup(first, rows, cols, i, j, 1, 0);
                            nOccup += isOccup(first, rows, cols, i, j, -1, 0);
                            nOccup += isOccup(first, rows, cols, i, j, 1, 1);
                            nOccup += isOccup(first, rows, cols, i, j, -1, -1);
                            nOccup += isOccup(first, rows, cols, i, j, 1, -1);
                            nOccup += isOccup(first, rows, cols, i, j, -1, 1);

                            if (first.get(i)[j] == 'L') {
                                second.get(i)[j] = nOccup == 0 ? '#' : 'L';
                            }
                            else if (first.get(i)[j] == '#') {
                                second.get(i)[j] = nOccup < 5 ? '#' : 'L';
                            } else {
                                second.get(i)[j] = '.';
                            }
                        }

                        changes |= second.get(i)[j] != first.get(i)[j];
                    }
                }

                grid1 = !use1 ? second : first;
                grid2 = use1 ? second : first;
                use1 = !use1;

                ++rounds;

                if (!changes) {
                    break;
                }
            }

            // Count occupied
            int occup = 0;
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    if (grid1.get(i)[j] == '#')
                        ++occup;

            System.out.print(part1 ? "Part 1: " : "Part 2: ");
            System.out.println(occup);
        } catch (Exception e) {
            System.err.println(e);
        }
    }
}
