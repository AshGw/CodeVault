import matplotlib.pyplot as plt
import requests
import random


url = 'https://random.org/integers/?num=1&min=2&max=10000&col=5&base=10&format=plain&end=new'


class PollenPath:
    def __init__(self, distance_m: int = 0):
        self.distance = distance_m
        self.x_points = [0]
        self.y_points = [0]
        random.seed(int(requests.get(url).text))

    @staticmethod
    def air_blow():
        return random.randint(2, 3)

    def setps(self):
        if self.air_blow() == 1:
            return [s for s in range(1, 3)]

        if self.air_blow() == 2:
            return [s for s in range(3, 10)]

        else:
            return [s for s in range(10, 30)]

    def go(self):
        while len(self.x_points) < self.distance:
            x_dir = random.choice([-1, 1]) * random.choice(self.setps())
            y_dir = random.choice([-1, 1]) * random.choice(self.setps())
            if x_dir == 0 and y_dir == 0:
                continue

            next_x = self.x_points[-1] + x_dir
            next_y = self.y_points[-1] + y_dir
            self.x_points.append(next_x)
            self.y_points.append(next_y)
        return self

    def visualize(self):
        plt.figure(figsize=(10, 6))
        plt.scatter(self.x_points, self.y_points, s=0.5, c=[
                    i for i in range(1, self.distance + 1)])
        plt.scatter(0, 0, c='green', s=100)
        plt.scatter(self.x_points[-1],
                    self.y_points[-1],
                    c='red',
                    edgecolors='none')
        plt.show()


if __name__ == '__main__':
    rw = PollenPath(50000)
    rw.go().visualize()
