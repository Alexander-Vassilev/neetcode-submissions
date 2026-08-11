public class DynamicArray {
    public int[] array;
    int size;

    public DynamicArray(int capacity) {
        array = new int[capacity];
        size = 0;
    }

    public int Get(int i) {
        return array[i];
    }

    public void Set(int i, int n) {
        array[i] = n;
    }

    public void PushBack(int n) {        
        if (size == array.Length) {
            Resize();
        }

        size++;
        array[size - 1] = n;
    }

    public int PopBack() {
        int output = array[size - 1];
        size--;

        return output;
    }

    private void Resize() {
        int newLen = array.Length * 2;
        int[] placeholder = new int[newLen];

        for (int i = 0; i < array.Length; i++) {
            placeholder[i] = array[i];
        }

        array = placeholder;
    }

    public int GetSize() {
        return size;
    }

    public int GetCapacity() {
        return array.Length;
    }
}
