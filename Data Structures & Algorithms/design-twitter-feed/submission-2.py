import copy
import heapq

class Twitter:

    def __init__(self):
        self.userDict = {} # Key = user, value = [[(timestep, post), ...], {followee, ...}]
        self.timestep = 0

    def initUser(self, userId: int) -> None:
        if userId not in self.userDict:
            self.userDict[userId] = [[], {userId}]
            heapq.heapify(self.userDict[userId][0])

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.timestep += 1
        self.initUser(userId)
        heapq.heappush(self.userDict[userId][0], (self.timestep, tweetId))

    def getNewsFeed(self, userId: int) -> List[int]:
        heap = []
        heapq.heapify(heap)
        followees = self.userDict[userId][1]
        retList = []

        for followee in followees:
            tweets = copy.copy(self.userDict[followee][0])
        
            while tweets:
                tweet = heapq.heappop(tweets)

                if len(heap) < 10:
                    heapq.heappush(heap, tweet)
                elif tweet[0] > heap[0][0]:
                    heapq.heappop(heap)
                    heapq.heappush(heap, tweet)
                else:
                    break
        
        while heap:
            tweet = heapq.heappop(heap)
            retList.append(tweet[1])
        
        retList.reverse()

        return retList

    def follow(self, followerId: int, followeeId: int) -> None:
        self.initUser(followerId)
        self.userDict[followerId][1].add(followeeId)
        print(self.userDict)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.initUser(followerId)
        print(self.userDict)

        if (followerId != followeeId) and (followeeId in self.userDict[followerId][1]):
            self.userDict[followerId][1].remove(followeeId)