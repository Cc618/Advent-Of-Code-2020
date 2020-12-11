import java.util.*;
import java.io.*;

class Problem {
    public static void main(String[] args) {
        try {
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
                        // Count occupied seats
                        int nOccup = 0;
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

            System.out.print("Part 1: ");
            System.out.println(occup);
        } catch (Exception e) {
            System.err.println(e);
        }
    }
}
