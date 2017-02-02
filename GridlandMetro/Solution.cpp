#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::vector;

struct Track {
    unsigned long row, start, end;

    bool operator < (const Track &a) const {
        if(row == a.row) {
            if (start == a.start)
                return end < a.end;
            return start < a.start;
        }
        return row < a.row;
    }
};

int main() {

    int trains(0);
    unsigned long trackLength(0), rows(0), columns(0), start(0), end(0), rowNum(0);
    vector<struct Track> trainTracks;

    cin >> rows >> columns >> trains;

    // Read in all sets of track coordinates, save them all into structs, save all structs into vector
    for(int i = 0; i < trains; ++i) {
        cin >> rowNum >> start >> end;

        trainTracks.push_back(Track());
        trainTracks.at(i).row = rowNum;
        trainTracks.at(i).start = start;
        trainTracks.at(i).end = end;
    }

    // Sort all track structs from lowest row to highest row, and then within each row from smallest (farthest left)
    // starting coordinate value to highest (farthest right) starting coordinate value
    sort(trainTracks.begin(), trainTracks.end());

    /*
     * Checks for overlapping tracks in each row. Because the list of structs was sorted, it compares tracks on the
     * left (smaller starting coordinate) to tracks on the right (with an equal or later starting coordinate). If the
     * track on the right ends before the one on the left, the right track is simply deleted. If the right track ends
     * after the left, the difference between the left and right tracks ending is added to the ending of the left track
     * and the right track is deleted. When a track is deleted in the above fashions, the index is pulled back, so that
     * the current left track can be compared to the next track, and this will continue to happen until the next
     * track is not overlapping the left one at all, in which case the right track becomes the new left most track, and
     * the comparison process starts over and over until all tracks within a row have been looked at.
     */
    if(trains > 0) {
        for (int i = 0; i < trainTracks.size() - 1; ++i) {
            if (trainTracks[i].row == trainTracks[i + 1].row) {
                Track &a = trainTracks[i];
                Track &b = trainTracks[i + 1];
                if (b.start <= a.end) {
                    if (b.end < a.end) {
                        trainTracks.erase(trainTracks.begin() + i + 1);
                    } else if (b.end >= a.end) {
                        a.end = b.end;
                        trainTracks.erase(trainTracks.begin() + i + 1);
                    }
                    --i;
                } else
                    continue;
            }
        }
    }

    // Once all overlapping tracks have been accounted for and consolidated into singular tracks, their distances can
    // simply be added up and subtracted from the total spaces on the grid.
    for(int i = 0; i < trainTracks.size(); i++) {
        trackLength += (trainTracks[i].end - trainTracks[i].start + 1);
    }

    cout << rows * columns - trackLength;
}

